/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:36:07 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 06:19:08 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			exec_42sh(char *cmd)
{
	int			i;
	t_conf		conf;

	i = 0;
	ft_parser(cmd, &conf);
	exec_get_paths();
	if (fd()->paths == NULL)
	{
		ft_is_builtin(conf.instr[i]->cmds[0]->param, g()->env);
		return ;
	}
	fd()->stdin = dup(0);
	fd()->stdout = dup(1);
	fd()->conf = &conf;
	while (i < conf.nb_instr)
	{
		exec_launch_instr(conf, &i);
		i++;
	}
	exec_free_all();
}

void			exec_launch_instr(t_conf conf, int *i)
{
	int		j;
	int		is_cmd;

	if (conf.instr[*i]->cmds)
	{
		j = 0;
		exec_malloc_fds(conf.instr[*i]->nb_cmd);
		while (j < conf.instr[*i]->nb_cmd)
		{
			exec_init_struct_fd(*conf.instr[*i], j);
			is_cmd = exec_do_execve(*i, &j);
		}
		exec_is_cmd(is_cmd, &j);
		exec_is_logic(i);
		exec_close_fds();
		dup2(fd()->stdin, 0);
		dup2(fd()->stdout, 1);
	}
}

void			exec_is_cmd(int is_cmd, int *j)
{
	if (is_cmd == 0)
	{
		if (fd()->file_out != NULL)
			exec_get_file_fd(1);
	}
	if (is_cmd == 1)
	{
		*j -= 1;
		if (fd()->file_out)
		{
			fd()->fd[*j][1] = exec_get_file_fd(fd()->fd[*j][1]);
			if (fd()->out_type == 1)
				exec_clear_file(fd()->fd[*j][1]);
			else if (fd()->out_type == 2)
			{
				if (lseek(fd()->fd[*j][1], 0, SEEK_END) < 0)
					ft_errors(ERR42_LSEEK);
			}
		}
		else
			fd()->fd[*j][1] = 1;
		exec_read_and_print(*j);
	}
}
