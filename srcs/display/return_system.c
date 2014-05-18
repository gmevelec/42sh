/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_system.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:38:02 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:03:48 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			return_system(void)
{
	restore_history_lines();
	add_to_history(g()->line);
	cursor_at_end();
	move_down();
	if (is_line_empty(g()->line))
	{
		clean_termcap();
		exec_42sh(g()->line);
		refresh_term();
	}
	ft_strdel(&g()->line);
	g()->line = ft_strnew(1);
	ft_strclr(g()->line);
	g()->cursor_pos = 0;
	ft_putstr(g()->prompt);
}
