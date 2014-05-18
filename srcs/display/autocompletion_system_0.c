/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion_system_0.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 23:32:40 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:00:39 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			autocompletion_activ(t_bool activ)
{
	if (activ == TRUE)
	{
		g()->activ.in_autocomp = TRUE;
		g()->autoc.rank++;
	}
	else
	{
		g()->autoc.rank = -1;
		if (g()->autoc.last)
			ft_strdel(&g()->autoc.last);
		g()->activ.in_autocomp = FALSE;
	}
}
