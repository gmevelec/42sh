/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:00:03 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/05 17:07:07 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <unistd.h>

char		**ft_duck(char **param, char **env)
{
	char		*popol;
	int			j;
	int			k;

	j = 0;
	popol = ft_strdup("\033[31m\\\033[0m_\033[34mO\033[0m\033[33m<\033[0m");
	while (j < (g()->terminal.col - 3))
	{
		k = j;
		while (k > 0)
		{
			ft_putstr(" ");
			k--;
		}
		ft_putendl(popol);
		j++;
		usleep(50000);
		if (j < (g()->terminal.col - 3))
			ft_putstr("\033[1A");
	}
	(void)param;
	return (env);
}
