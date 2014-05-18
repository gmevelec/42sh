/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 17:31:18 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:00:33 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			left_arrow_system(void)
{
	int			i;
	long		virtual_pos;

	i = 0;
	if (g()->cursor_pos > 0)
	{
		g()->cursor_pos--;
		virtual_pos = g()->cursor_pos + ft_strlen(g()->prompt);
		if ((virtual_pos + 1) % g()->terminal.col == 0)
		{
			move_up();
			while (++i < g()->terminal.col)
				move_right();
		}
		else
			move_left();
	}
}

void			right_arrow_system(void)
{
	long		virtual_pos;

	if (g()->cursor_pos < (int)ft_strlen(g()->line))
	{
		g()->cursor_pos++;
		virtual_pos = g()->cursor_pos + ft_strlen(g()->prompt);
		if ((virtual_pos % g()->terminal.col) == 0)
			move_down();
		else
			move_right();
	}
}

void			up_arrow_system(void)
{
	if (g()->activ.in_history && g()->actual_hist && g()->actual_hist->next)
	{
		g()->actual_hist = g()->actual_hist->next;
		cursor_at_end();
		delete_len_left(ft_strlen(g()->line));
		line_add_str(g()->actual_hist->line);
	}
	else if (!g()->activ.in_history && g()->actual_hist)
	{
		g()->activ.in_history = TRUE;
		backup_actual_line();
		cursor_on_prompt();
		delete_len_right(ft_strlen(g()->line));
		line_add_str(g()->actual_hist->line);
	}
}

void			down_arrow_system(void)
{
	if (g()->actual_hist && g()->actual_hist && g()->actual_hist->prev)
	{
		g()->actual_hist = g()->actual_hist->prev;
		cursor_at_end();
		delete_len_left(ft_strlen(g()->line));
		line_add_str(g()->actual_hist->line);
	}
	else if (g()->activ.in_history)
	{
		g()->activ.in_history = FALSE;
		cursor_on_prompt();
		delete_len_right(ft_strlen(g()->line));
		restore_line();
		line_add_str(g()->line);
		delete_len_left(g()->cursor_pos);
		cursor_at_end();
	}
}
