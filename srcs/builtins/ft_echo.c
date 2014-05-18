/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:31:33 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/11 18:25:03 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

static void	ft_echo1(char **param, int *i, int *flag)
{
	if (ft_strcmp(param[*i], "-n"))
	{
		ft_putstr(param[*i]);
		if (param[*i + 1])
			ft_putchar(' ');
		(*flag)++;
	}
	(*i)++;
}

static void	ft_echo2(char **param, int *i, int *flag)
{
	(*flag)++;
	ft_putstr(param[*i]);
	if (param[*i + 1])
		ft_putchar(' ');
	(*i)++;
}

static void	ft_echo3(void)
{
	tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	ft_putendl("%");
}

static int	ft_echo4(char **param, int i)
{
	while (param[i] && !ft_strcmp(param[i], "-n"))
		i++;
	return (i);
}

char		**ft_echo(char **param, char **environ)
{
	int		i;
	int		flag;

	if (!param[1])
	{
		ft_putchar('\n');
		return (environ);
	}
	flag = 0;
	i = ft_echo4(param, 1);
	if (param[i])
	{
		while (param[i])
		{
			if (flag == 0)
				ft_echo1(param, &i, &flag);
			else
				ft_echo2(param, &i, &flag);
		}
		if (ft_strcmp(param[1], "-n"))
			ft_putchar('\n');
		else
			ft_echo3();
	}
	return (environ);
}
