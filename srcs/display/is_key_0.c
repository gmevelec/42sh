/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:29:08 by crenault          #+#    #+#             */
/*   Updated: 2014/03/10 20:10:56 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <term.h>

int				is_key_ctrl_d(char *keytab)
{
	if (keytab[0] == 4 && keytab[1] == 0 && keytab[2] == 0 && keytab[3] == 0)
	{
		if (!ft_strlen(g()->line))
			ft_exit(NULL, NULL);
		else
			tputs(tgetstr("bl", NULL), 1, tputs_putchar);
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_ctrl_r(char *keytab)
{
	if (keytab[0] == 18 && keytab[1] == 0 && keytab[2] == 0 && keytab[3] == 0)
	{
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_tab(char *keytab)
{
	if (keytab[0] == 9 && keytab[1] == 0 && keytab[2] == 0 && keytab[3] == 0)
	{
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_home(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 72 && keytab[3] == 0)
	{
		if (g()->activ.esc == TRUE)
		{
			delete_len_left(g()->cursor_pos);
			g()->activ.esc = FALSE;
		}
		else
			cursor_on_prompt();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_end(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 70 && keytab[3] == 0)
	{
		if (g()->activ.esc == TRUE)
		{
			delete_len_right(ft_strlen(g()->line) - g()->cursor_pos);
			g()->activ.esc = FALSE;
		}
		else
			cursor_at_end();
		return (TRUE);
	}
	return (FALSE);
}
