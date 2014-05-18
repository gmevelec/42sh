/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:35:14 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 05:55:01 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

short			exec_search_cmd(void)
{
	int		i;
	int		is;
	char	*tmp_0;
	char	*tmp_1;
	char	*tmp_2;

	i = 0;
	is = exec_search_if_builtin_and_access();
	if (is >= -1)
		return (is);
	while (fd()->paths[i])
	{
		tmp_0 = ft_strdup(fd()->paths[i]);
		tmp_1 = ft_strjoin(tmp_0, "/");
		free(tmp_0);
		tmp_2 = ft_strjoin(tmp_1, fd()->cmds[0]);
		free(tmp_1);
		if (exec_search_cmd_2(tmp_2) == 1)
			return (1);
		free(tmp_2);
		i++;
	}
	ft_errors(ERR42_CMDNOTFOUND);
	return (0);
}

short			exec_search_cmd_2(char *tmp_2)
{
	if (access(tmp_2, X_OK) == 0)
	{
		fd()->cmds[0] = tmp_2;
		free(tmp_2);
		return (1);
	}
	return (0);
}

short			exec_search_if_builtin_and_access(void)
{
	if (ft_is_builtin(fd()->cmds, g()->env))
		return (2);
	if (builtin_last_return(fd()->cmds[0]) == 1)
		return (2);
	if (access(fd()->cmds[0], F_OK) == 0)
	{
		if (access(fd()->cmds[0], X_OK) == 0)
		{
			if (fd()->cmds[0][0] == '.' && fd()->cmds[0][1] == '/')
				return (1);
			if (fd()->cmds[0][0] == '/')
				return (1);
		}
		else
		{
			ft_errors(ERR42_RIGHTS);
			return (0);
		}
	}
	if (fd()->paths == NULL)
	{
		ft_errors(ERR42_CMDNOTFOUND);
		return (-1);
	}
	return (-2);
}
