/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:36:24 by crenault          #+#    #+#             */
/*   Updated: 2014/03/10 11:45:33 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

int				is_key_pup(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 53
		&& keytab[3] == 126)
	{
		page_up();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_pdown(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 54
		&& keytab[3] == 126)
	{
		page_down();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_delete(char *keytab)
{
	if (keytab[0] == 127 && keytab[1] == 0 && keytab[2] == 0 && keytab[3] == 0)
	{
		if (g()->activ.esc == TRUE)
		{
			delete_len_left(get_size_left_word());
			g()->activ.esc = FALSE;
		}
		else
			deletion_system_left();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_delete_right(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 51
		&& keytab[3] == 126)
	{
		if (g()->activ.esc == TRUE)
		{
			delete_len_right(get_size_right_word());
			g()->activ.esc = FALSE;
		}
		else
			deletion_system_right();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_esc(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 0 && keytab[2] == 0 && keytab[3] == 0)
	{
		g()->activ.esc = (g()->activ.esc == TRUE) ? FALSE : TRUE;
		return (TRUE);
	}
	return (FALSE);
}
