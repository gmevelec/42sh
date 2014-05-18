/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:36:41 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/12 19:45:58 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			exec_cmd(int i)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		exec_cmd_father(i);
	else if (pid == 0)
		exec_cmd_son(i);
	else
		ft_errors(ERR42_FORK);
}

void			exec_cmd_father(int i)
{
	wait(&status()->status);
	if (close(fd()->fd[i][1]) < 0)
		ft_errors(ERR42_CLOSE);
	if (dup2(fd()->fd[i][0], 0) < 0)
		ft_errors(ERR42_DUP2);
}

void			exec_cmd_son(int i)
{
	if (fd()->nb_cmds > 1 || fd()->file_out)
	{
		if (close(fd()->fd[i][0]) < 0)
			ft_errors(ERR42_CLOSE);
		if (dup2(fd()->fd[i][1], 1) < 0)
			ft_errors(ERR42_DUP2);
	}
	if (fd()->file_in)
	{
		fd()->nb_forks *= -1;
		if (fd()->nb_forks == 1)
		{
			if (i > 0)
				exec_cmd(i);
			exec_read_file_in(fd()->file_in);
		}
	}
	execve(fd()->cmds[0], fd()->cmds, g()->env);
	ft_errors(ERR42_EXECVE);
}
