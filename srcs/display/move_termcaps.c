/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 14:35:48 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:00:48 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <term.h>

void			move_up(void)
{
	tputs(tgetstr("up", NULL), 1, tputs_putchar);
}

void			move_down(void)
{
	tputs(tgetstr("do", NULL), 1, tputs_putchar);
}

void			move_left(void)
{
	tputs(tgetstr("le", NULL), 1, tputs_putchar);
}

void			move_right(void)
{
	tputs(tgetstr("nd", NULL), 1, tputs_putchar);
}
