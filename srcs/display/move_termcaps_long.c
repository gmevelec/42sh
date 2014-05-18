/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_termcaps_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 14:35:48 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:03:46 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <term.h>

void			move_up_long(int len)
{
	if (len > 0)
		tputs(tgoto(tgetstr("UP", NULL), 0, len), 1, tputs_putchar);
}

void			move_down_long(int len)
{
	if (len > 0)
		tputs(tgoto(tgetstr("DO", NULL), 0, len), 1, tputs_putchar);
}

void			move_left_long(int len)
{
	if (len > 0)
		tputs(tgoto(tgetstr("LE", NULL), 0, len), 1, tputs_putchar);
}

void			move_right_long(int len)
{
	if (len > 0)
		tputs(tgoto(tgetstr("RI", NULL), 0, len), 1, tputs_putchar);
}
