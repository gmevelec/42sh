/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:15:21 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 18:15:21 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

#include <stdio.h>

void			exec_is_logic(int *i)
{
	if (fd()->conf->logic_type[*i + 1] == 1 && status()->status == 0)
	{
		while (*i < fd()->conf->nb_instr)
		{
			if (fd()->conf->logic_type[*i + 1] != 1)
				break ;
			(*i)++;
		}
	}
	if (fd()->conf->logic_type[*i + 1] == 2 && status()->status != 0)
	{
		while (*i < fd()->conf->nb_instr)
		{
			if (fd()->conf->logic_type[*i + 1] != 2)
				break ;
			(*i)++;
		}
	}
}

short			exec_do_execve(int i, int *j)
{
	int		type;

	type = 0;
	fd()->i = *j;
	if (fd()->nb_para > 0)
		type = exec_search_cmd();
	if ((fd()->file_in && access(fd()->file_in, F_OK) < 0) && (type != 0 ||
		fd()->nb_para == 0))
	{
		ft_errors(ERR42_FILEIN);
		type = 0;
	}
	if (type == 1)
		exec_cmd(*j);
	*j += 1;
	return (type);
}

void			exec_read_and_print(int i)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	while ((ret = read(fd()->fd[i][0], buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ft_putstr_fd(buf, fd()->fd[i][1]);
	}
}
