/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 17:36:35 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 05:42:06 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			exec_get_paths(void)
{
	char	*path;
	char	**paths;

	path = ft_getenv("PATH=", g()->env);
	if (path == NULL)
	{
		ft_errors(ERR42_NOPATH);
		fd()->paths = NULL;
		return ;
	}
	fd()->paths = exec_split_paths(path);
	ft_strdel(&path);
	if (fd()->paths == NULL)
		ft_errors(ERR42_NOPATH);
}

char			**exec_split_paths(char *env)
{
	int		i;
	int		len;
	char	*tmp;
	char	**paths;

	i = 0;
	len = exec_count_paths(env);
	tmp = env;
	paths = (char **)malloc(sizeof(char *) * len + 1);
	if (paths == NULL)
		return (NULL);
	paths[len] = NULL;
	while (i < len)
	{
		tmp = exec_strcpy_paths(paths, tmp, i);
		i++;
	}
	return (paths);
}

int				exec_count_paths(char *env)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (env[i])
	{
		if (env[i] == ':')
			nbr++;
		i++;
	}
	return (nbr + 1);
}

char			*exec_strcpy_paths(char **s1, char *s2, int i)
{
	int		j;

	j = 0;
	while (s2[j] && s2[j] != ':')
		j++;
	s1[i] = (char *)malloc(sizeof(char) * j + 1);
	if (s1[i] == NULL)
		return (NULL);
	s1[i][j] = '\0';
	j = 0;
	while (s2[j] && s2[j] != ':')
	{
		s1[i][j] = s2[j];
		j++;
	}
	return (s2 + j + 1);
}
