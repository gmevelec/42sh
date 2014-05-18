/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:36:24 by crenault          #+#    #+#             */
/*   Updated: 2014/03/10 11:45:39 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

int				is_key_shift_up(char *keytab)
{
	if (keytab[0] == 50 && keytab[1] == 65 && keytab[2] == 0 && keytab[3] == 0)
	{
		if (g()->cursor_pos >= g()->terminal.col)
			left_arrow_system_long(g()->terminal.col);
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_shift_down(char *keytab)
{
	if (keytab[0] == 50 && keytab[1] == 66 && keytab[2] == 0 && keytab[3] == 0)
	{
		if (((int)ft_strlen(g()->line) - g()->cursor_pos) >= g()->terminal.col)
			right_arrow_system_long(g()->terminal.col);
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_shift_left(char *keytab)
{
	int			decal_left;

	if (keytab[0] == 50 && keytab[1] == 68 && keytab[2] == 0 && keytab[3] == 0)
	{
		decal_left = (g()->cursor_pos + ft_strlen(g()->prompt))
		% g()->terminal.col;
		left_arrow_system_long(decal_left);
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_shift_right(char *keytab)
{
	int			decal_left;

	if (keytab[0] == 50 && keytab[1] == 67 && keytab[2] == 0 && keytab[3] == 0)
	{
		decal_left = (g()->cursor_pos + ft_strlen(g()->prompt))
		% g()->terminal.col;
		right_arrow_system_long(g()->terminal.col - decal_left - 1);
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_esc_char(char *keytab)
{
	if (keytab[0] == 27 && (keytab[1] != 0 && keytab[2] != 0 && keytab[3] != 0))
		return (TRUE);
	return (FALSE);
}
