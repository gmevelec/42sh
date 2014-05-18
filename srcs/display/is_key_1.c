/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:34:59 by crenault          #+#    #+#             */
/*   Updated: 2014/03/10 20:12:10 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

int				is_key_up_arrow(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 65 && keytab[3] == 0)
	{
		up_arrow_system();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_down_arrow(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 66 && keytab[3] == 0)
	{
		down_arrow_system();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_left_arrow(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 68 && keytab[3] == 0)
	{
		left_arrow_system();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_right_arrow(char *keytab)
{
	if (keytab[0] == 27 && keytab[1] == 91 && keytab[2] == 67 && keytab[3] == 0)
	{
		right_arrow_system();
		return (TRUE);
	}
	return (FALSE);
}

int				is_key_return(char *keytab)
{
	if (keytab[0] == 10 && keytab[1] == 0 && keytab[2] == 0 && keytab[3] == 0)
	{
		return_system();
		return (TRUE);
	}
	return (FALSE);
}
