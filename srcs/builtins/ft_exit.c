/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 17:38:54 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/03 23:45:12 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

char		**ft_exit(char **param, char **environ)
{
	(void)param;
	ft_putendl("exit");
	clean_termcap();
	_exit(0);
	return (environ);
}
