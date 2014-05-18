/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:04:28 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/26 18:04:29 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../../headers/sh42.h"

static char	*ft_up(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

static char	*set_newenv(char **param, int size)
{
	char		*str;

	str = malloc(sizeof(char) * (size + 1));
	str = ft_strcpy(str, ft_up(param[1]));
	str = ft_strjoin(str, "=");
	str = ft_strjoin(str, param[2]);
	return (str);
}

char		*ft_set_env(char **param, char *env)
{
	char	*str;

	if (!ft_strcmp(param[3], "1"))
		str = set_newenv(param, ft_strlen(param[1]));
	else if (!ft_strcmp(param[3], "0"))
		str = ft_strjoin(env, param[2]);
	else
		ft_putstr("Wrong param, it must be 0 or 1.\n");
	return (str);
}

char		**ft_setenv(char **param, char **env)
{
	int		i;

	i = 0;
	if (!param[1] || !param[2] || !param[3])
	{
		ft_putstr("Usage: [Arg] [Value] [0 or 1].\n");
		return (env);
	}
	if (ft_strchr(param[1], '=') || ft_strchr(param[2], '='))
	{
		ft_putstr("Error don't use = in params\n");
		return (env);
	}
	while (env[i] && ft_strncmp(env[i], ft_up(param[1]), ft_strlen(param[1])))
		i++;
	if (env[i])
		env[i] = ft_set_env(param, env[i]);
	else
	{
		env[i] = set_newenv(param, ft_strlen(param[1]));
		env[i + 1] = NULL;
	}
	return (env);
}
