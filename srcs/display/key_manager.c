/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 15:05:25 by crenault          #+#    #+#             */
/*   Updated: 2014/03/10 11:46:03 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

int				key_manager(char *keytab)
{
	int				i;
	static int		(*f[])(char *) =

	{
	is_key_ctrl_d, is_key_ctrl_r, is_key_tab, is_key_home, is_key_end,
	is_key_up_arrow, is_key_down_arrow, is_key_left_arrow,
	is_key_right_arrow, is_key_return, is_key_pup, is_key_pdown,
	is_key_delete, is_key_esc, is_key_delete_right,
	is_key_shift_up, is_key_shift_down, is_key_shift_left,
	is_key_shift_right, is_key_esc_char, NULL
	};
	i = 0;
	while (f[i] != NULL)
	{
		if (f[i](keytab) == TRUE)
			return (1);
		i++;
	}
	line_add_str(keytab);
	if (g()->activ.in_history)
		backup_history_line();
	return (0);
}
