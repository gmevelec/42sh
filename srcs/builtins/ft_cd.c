/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:11:56 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/26 18:02:04 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../headers/sh42.h"

static char	*ft_envcpy(char *s1, char *s2, int i)
{
	int		j;

	j = 0;
	while (s2[i])
	{
		s1[j] = s2[i];
		j++;
		i++;
	}
	s1[j] = '\0';
	return (s1);
}

char		*ft_getenv(char *name, char **env)
{
	char	*str;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(name, env[i], ft_strlen(name)))
		i++;
	if (env[i])
	{
		str = malloc(sizeof(char) * (ft_strlen(env[i]) - ft_strlen(name) + 1));
		str = ft_envcpy(str, env[i], ft_strlen(name));
	}
	return (str);
}

char		**get_param(char *s1, char *s2)
{
	char	**tab_t;

	tab_t = malloc(sizeof(char *) * 5);
	tab_t[0] = ft_strdup("cd");
	tab_t[1] = ft_strdup(s1);
	tab_t[2] = ft_strdup(s2);
	tab_t[3] = ft_strdup("1");
	tab_t[4] = NULL;
	return (tab_t);
}

char		**ft_cd(char **param, char **environ)
{
	char	*str;
	char	*pwd;
	char	**tab_t;

	if (param[2])
	{
		ft_putstr("cd: too many arguments\n");
		return (environ);
	}
	pwd = ft_getenv("PWD=", environ);
	if (!param[1] || !ft_strcmp(param[1], "~"))
		environ = ft_cd_no_args(environ);
	else if (!ft_strcmp(param[1], "-"))
		environ = ft_cd_back(environ);
	else
		environ = ft_cd_args(param, environ, pwd);
	return (environ);
}
