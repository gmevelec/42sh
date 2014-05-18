/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:39:28 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/03 16:17:51 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../headers/sh42.h"

static char		*ft_up(char *str)
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

char			**ft_unsetenv(char **param, char **environ)
{
	int		i;
	int		size;

	i = 0;
	if (!param[1])
	{
		ft_putstr("Usage: [arg].\n");
		return (environ);
	}
	size = ft_strlen(param[1]);
	while (environ[i] && ft_strncmp(environ[i], ft_up(param[1]), size))
		i++;
	if (environ[i])
		ft_strclr(environ[i]);
	else
		ft_putstr("Specified name doesn't exist\n");
	return (environ);
}
