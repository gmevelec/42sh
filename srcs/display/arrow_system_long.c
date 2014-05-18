/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_system_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 00:42:55 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 14:05:42 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void		left_arrow_system_long(int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		left_arrow_system();
		i++;
	}
}

void		right_arrow_system_long(int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		right_arrow_system();
		i++;
	}
}
