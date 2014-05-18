/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_system.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:05:31 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:05:09 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			backup_history_line(void)
{
	if (!g()->actual_hist->backup_line)
		g()->actual_hist->backup_line = ft_strdup(g()->actual_hist->line);
	ft_strdel(&g()->actual_hist->line);
	g()->actual_hist->line = ft_strdup(g()->line);
}

void			restore_history_lines(void)
{
	t_hist		*cursor;

	cursor = g()->first_hist;
	while (cursor)
	{
		if (cursor->backup_line)
		{
			ft_strdel(&cursor->line);
			cursor->line = ft_strdup(cursor->backup_line);
			ft_strdel(&cursor->backup_line);
		}
		cursor = cursor->next;
	}
}

static t_hist	*new_hist(char *line)
{
	t_hist		*hist;

	hist = (t_hist *)malloc(sizeof(t_hist));
	hist->line = ft_strdup(line);
	hist->backup_line = NULL;
	hist->next = NULL;
	hist->prev = NULL;
	return (hist);
}

static void		push_front(t_hist **first_hist, char *line)
{
	t_hist		*newh;

	if (!*first_hist)
	{
		*first_hist = new_hist(line);
		g()->actual_hist = *first_hist;
	}
	else
	{
		newh = new_hist(line);
		(*first_hist)->prev = newh;
		newh->next = *first_hist;
		*first_hist = newh;
		g()->actual_hist = *first_hist;
	}
}

void			add_to_history(char *line)
{
	if (is_line_empty(line))
		push_front(&g()->first_hist, line);
	if (g()->activ.in_history)
		g()->activ.in_history = FALSE;
}
