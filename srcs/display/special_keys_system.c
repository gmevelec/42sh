/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys_system.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 21:01:10 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:04:13 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <term.h>

void			cursor_on_prompt(void)
{
	int			i;

	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	i = g()->cursor_pos;
	while (i > 0)
	{
		left_arrow_system();
		i--;
	}
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
}

void			cursor_at_end(void)
{
	int			i;
	int			len;

	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	i = g()->cursor_pos;
	len = ft_strlen(g()->line);
	while (i < len)
	{
		right_arrow_system();
		i++;
	}
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
}

void			page_up(void)
{
	right_arrow_system_long(get_size_right_word());
}

void			page_down(void)
{
	left_arrow_system_long(get_size_left_word());
}
