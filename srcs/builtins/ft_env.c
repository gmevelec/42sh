/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:31:03 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/13 10:41:10 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

static void		ft_print_env(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

char			**ft_env(char **param, char **environ)
{
	int		i;

	i = 0;
	while (environ[i])
	{
		if (environ[i][0] != '\0')
			ft_print_env(environ[i]);
		i++;
	}
	i = 0;
	while (param[i])
	{
		if (ft_strcmp(param[i], "env"))
			ft_env_2(param, i);
		i++;
	}
	return (environ);
}

void			ft_env_2(char **param, int i)
{
	int		j;

	j = 0;
	while (param[i][j])
	{
		if (param[i][j] == '=')
			ft_putendl(param[i]);
		j++;
	}
}
