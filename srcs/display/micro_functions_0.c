/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_functions_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:38:02 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:05:08 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

int				tputs_putchar(int c)
{
	ft_putchar(c);
	return (1);
}

void			add_char_to_line(char c)
{
	char		*new_line;
	int			i;
	int			len;

	new_line = ft_strnew(ft_strlen(g()->line) + 1);
	i = 0;
	len = ft_strlen(g()->line);
	while (i < g()->cursor_pos)
	{
		new_line[i] = g()->line[i];
		i++;
	}
	new_line[i] = c;
	while (i < len)
	{
		new_line[i + 1] = g()->line[i];
		i++;
	}
	ft_strclr(g()->line);
	ft_strdel(&g()->line);
	g()->line = ft_strdup(new_line);
	ft_strdel(&new_line);
}

void			backup_actual_line(void)
{
	ft_strclr(g()->backup_line);
	g()->backup_line = ft_strdup(g()->line);
}

void			restore_line(void)
{
	ft_strdel(&g()->line);
	g()->line = ft_strdup(g()->backup_line);
	ft_strdel(&g()->backup_line);
}

int				is_line_empty(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}
