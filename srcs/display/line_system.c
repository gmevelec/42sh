/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 19:11:48 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:05:03 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <term.h>

void			rewrite_from(int from)
{
	int			len;
	int			i;

	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	i = from;
	len = ft_strlen(g()->line);
	while (i < len)
	{
		ft_putchar(g()->line[i]);
		i++;
	}
	ft_putchar(' ');
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
}

void			line_add_str(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		line_add_char(str[i]);
		i++;
	}
}

void			line_add_char(char c)
{
	int		virtual_pos;
	long	real;
	int		decal_left;
	int		diff_curs;
	int		nbr_lines;

	if (!ft_isprint(c))
		return ;
	add_char_to_line(c);
	rewrite_from(g()->cursor_pos);
	real = g()->cursor_pos + ft_strlen(g()->prompt);
	virtual_pos = ft_strlen(g()->line) + ft_strlen(g()->prompt);
	decal_left = (real + 1) % g()->terminal.col;
	diff_curs = virtual_pos - (real + 1);
	nbr_lines = (diff_curs + decal_left) / g()->terminal.col;
	if (nbr_lines > 0)
	{
		move_left_long(g()->terminal.col);
		move_right_long(((real + 1) % g()->terminal.col));
		move_up_long(nbr_lines);
	}
	else
		move_left_long((ft_strlen(g()->line) + ft_strlen(g()->prompt)) - real);
	g()->cursor_pos++;
}

void			line_del_char_left(void)
{
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(g()->line) - 1;
	while (i < g()->cursor_pos + 1)
		i++;
	while (i <= len)
	{
		g()->line[i - 1] = g()->line[i];
		i++;
	}
	g()->line[i - 1] = '\0';
}

void			line_del_char_right(void)
{
	int			i;
	int			len;

	i = 0;
	len = ft_strlen(g()->line) - 1;
	while (i <= g()->cursor_pos)
		i++;
	while (i <= len)
	{
		g()->line[i - 1] = g()->line[i];
		i++;
	}
	g()->line[i - 1] = '\0';
}
