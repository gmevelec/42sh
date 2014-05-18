/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_termcaps_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 14:35:48 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:04:52 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <term.h>

void			move_up_long(int len)
{
	tputs(tgoto(tgetstr("UP", NULL), 0, len), 1, tputs_putchar);
}

void			move_down_long(int len)
{
	tputs(tgoto(tgetstr("DO", NULL), 0, len), 1, tputs_putchar);
}

void			move_left_long(int len)
{
	tputs(tgoto(tgetstr("LE", NULL), 0, len), 1, tputs_putchar);
}

void			move_right_long(int len)
{
	tputs(tgoto(tgetstr("RI", NULL), 0, len), 1, tputs_putchar);
}
