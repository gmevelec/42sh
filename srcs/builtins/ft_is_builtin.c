/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:02:46 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/26 18:04:10 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

char			**ft_newenv(char **environ)
{
	char	**env;
	int		i;

	i = 0;
	while (environ[i])
		i++;
	env = malloc(sizeof(char **) * (i + 2));
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i + 1] = NULL;
	return (env);
}

int				ft_is_builtin(char **param, char **environ)
{
	int				i;
	static t_ptr	ptr[7] =

	{
	{&ft_cd, "cd"},
	{&ft_echo, "echo"},
	{&ft_exit, "exit"},
	{&ft_env, "env"},
	{&ft_setenv, "setenv"},
	{&ft_duck, "duck"},
	{&ft_unsetenv, "unsetenv"}
	};
	i = -1;
	while (++i < 8)
	{
		if (!ft_strcmp(ptr[i].name, param[0]))
		{
			ptr[i].func(param, environ);
			return (1);
		}
	}
	return (0);
}
