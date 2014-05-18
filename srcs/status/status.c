/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 08:47:02 by zsarour           #+#    #+#             */
/*   Updated: 2014/02/27 08:47:02 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

t_status		*status(void)
{
	static t_status		*status;

	if (!status)
		status = (t_status *)malloc(sizeof(t_status) * 1);
	return (status);
}

short			builtin_last_return(char *cmd)
{
	if (ft_strcmp(cmd, "$?") == 0)
	{
		write(1, "\033[32m", 6);
		if (status()->status != 0)
			write(2, "\033[31m", 6);
		ft_putnbr(status()->status);
		ft_putchar('\n');
		write(1, "\033[0m", 5);
		return (1);
	}
	return (0);
}
