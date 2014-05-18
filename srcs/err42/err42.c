/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:36:52 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/12 19:46:36 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			ft_errors(short err)
{
	write(2, "\033[34m", 6);
	if (err == ERR42_RIGHTS)
		ft_putstr_fd("{ 42sh: permission denied\n", 2);
	else if (err == ERR42_GETENV)
		ft_putstr_fd("{ Error: Getenv recovery failed\n", 2);
	else if (err == ERR42_GATTR)
		ft_putstr_fd("{ Error: tcgetattr recovery failed\n", 2);
	else if (err == ERR42_SATTR)
		ft_putstr_fd("{ Error: tcsetattr recovery failed\n", 2);
	else if (err == ERR42_FILEIN)
	{
		ft_putstr_fd("{ 42sh: no such file or directory: ", 2);
		ft_putendl_fd(fd()->file_in, 2);
		status()->status = 1;
	}
	else
		ft_errors_2(err);
	write(2, "\033[0m", 5);
}

void			ft_errors_2(short err)
{
	if (err == ERR42_EXECVE)
	{
		ft_putstr_fd("{ 42sh: ", 2);
		ft_putstr_fd(fd()->cmds[0], 2);
		ft_putstr_fd(": is not a binary file\n", 2);
		write(2, "\033[0m", 5);
		_exit(EXIT_FAILURE);
	}
	else if (err == ERR42_CMDNOTFOUND)
	{
		ft_putstr_fd("{ 42sh: ", 2);
		ft_putstr_fd(fd()->cmds[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		status()->status = 127;
	}
	else if (err == ERR42_NOPATH)
	{
		ft_putstr_fd("{ 42sh: PATH not found\n", 2);
	}
}
