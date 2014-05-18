/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:50:51 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 05:47:49 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

t_fd			*fd(void)
{
	static t_fd	*fd;

	if (fd == NULL)
	{
		fd = (t_fd *)malloc(sizeof(t_fd) * 1);
		if (fd == NULL)
			ft_errors(ERR42_MALLOC);
	}
	return (fd);
}

void			exec_malloc_fds(int nbr)
{
	int		i;

	i = 0;
	fd()->fd = (int **)malloc(sizeof(int *) * nbr);
	if (fd()->fd == NULL)
		ft_errors(ERR42_MALLOC);
	while (i < nbr)
	{
		fd()->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (fd()->fd[i] == NULL)
			ft_errors(ERR42_MALLOC);
		if (pipe(fd()->fd[i]) < 0)
			ft_errors(ERR42_PIPE);
		i++;
	}
}

void			exec_init_struct_fd(t_instr instr, int i)
{
	fd()->nb_cmds = instr.nb_cmd;
	fd()->nb_para = instr.cmds[i]->param_nb;
	fd()->out_type = instr.cmds[i]->out_type;
	fd()->nb_forks = -1;
	fd()->cmds = instr.cmds[i]->param;
	fd()->file_in = instr.cmds[i]->file_in;
	fd()->file_out = instr.cmds[i]->file_out;
}

void			exec_close_fds(void)
{
	int		i;

	i = 0;
	while (i < fd()->nb_cmds)
	{
		if (close(fd()->fd[i][0]) < 0)
			ft_errors(ERR42_CLOSE);
		free(fd()->fd[i]);
		fd()->fd[i] = NULL;
		i++;
	}
	free(fd()->fd);
	fd()->fd = NULL;
}
