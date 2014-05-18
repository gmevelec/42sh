/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:36:29 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/07 17:36:29 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <fcntl.h>

int				exec_get_file_fd(int fd_file)
{
	int		new_fd;

	if (access(fd()->file_out, F_OK) < 0)
	{
		if ((new_fd = creat(fd()->file_out, S_IRUSR | S_IWUSR |
			S_IRGRP | S_IROTH)) >= 0)
			return (new_fd);
		else
		{
			ft_errors(ERR42_CREAT);
			return (fd_file);
		}
	}
	if ((new_fd = open(fd()->file_out, O_RDWR)) >= 0)
		return (new_fd);
	ft_errors(ERR42_RIGHTS);
	return (fd_file);
}

void			exec_clear_file(int fd)
{
	int		i;
	char	buf[1];

	i = 0;
	while (read(fd, buf, 1) > 0)
		i++;
	if (lseek(fd, 0, SEEK_SET) < 0)
		ft_errors(ERR42_LSEEK);
	while (i > 0)
	{
		write(fd, "\0", 1);
		i--;
	}
	if (lseek(fd, 0, SEEK_SET) < 0)
		ft_errors(ERR42_LSEEK);
}

void			exec_read_file_in(char *file)
{
	int		new_fd;

	if (access(file, F_OK) == 0)
	{
		new_fd = open(file, O_RDONLY);
		if (new_fd == -1)
			ft_errors(ERR42_OPEN);
		if (dup2(new_fd, 0) < 0)
			ft_errors(ERR42_DUP2);
	}
	else
		ft_errors(ERR42_FILEIN);
}
