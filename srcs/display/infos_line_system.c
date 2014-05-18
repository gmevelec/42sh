/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_line_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:19:50 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:05:12 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

int				get_size_left_word(void)
{
	int			i;
	int			count;

	count = 0;
	i = g()->cursor_pos - 1;
	while (ft_isspace(g()->line[i]) || g()->line[i] == ',')
	{
		count++;
		i--;
	}
	while (i > 0 && !ft_isspace(g()->line[i]) && g()->line[i] != ',')
	{
		count++;
		i--;
	}
	count++;
	return (count);
}

int				get_size_right_word(void)
{
	int			i;
	int			count;

	count = 0;
	i = g()->cursor_pos;
	while (ft_isspace(g()->line[i]) || g()->line[i] == ',')
	{
		count++;
		i++;
	}
	while (g()->line[i] && !ft_isspace(g()->line[i]) && g()->line[i] != ',')
	{
		count++;
		i++;
	}
	return (count);
}
