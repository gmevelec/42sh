/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletion_system.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:46:38 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:05:40 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <term.h>

void			deletion_system_left(void)
{
	if (g()->cursor_pos > 0)
	{
		left_arrow_system();
		tputs(tgetstr("sc", NULL), 1, tputs_putchar);
		rewrite_from(g()->cursor_pos + 1);
		tputs(tgetstr("rc", NULL), 1, tputs_putchar);
		line_del_char_left();
	}
	else
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
}

void			deletion_system_right(void)
{
	if (g()->cursor_pos < (long)ft_strlen(g()->line))
	{
		tputs(tgetstr("sc", NULL), 1, tputs_putchar);
		rewrite_from(g()->cursor_pos + 1);
		tputs(tgetstr("rc", NULL), 1, tputs_putchar);
		line_del_char_right();
	}
	else
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
}

void			delete_len_left(int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		deletion_system_left();
		i++;
	}
}

void			delete_len_right(int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		deletion_system_right();
		i++;
	}
}
