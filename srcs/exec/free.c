/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 16:56:13 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 06:23:38 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			exec_free_all(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < fd()->conf->nb_instr)
	{
		j = 0;
		while (j < fd()->conf->instr[i]->nb_cmd)
		{
			free(fd()->conf->instr[i]->cmds[j]->param);
			free(fd()->conf->instr[i]->cmds[j]->name);
			free(fd()->conf->instr[i]->cmds[j]);
			j++;
		}
		free(fd()->conf->instr[i]->cmds);
		free(fd()->conf->instr[i]);
		i++;
	}
	free(fd()->conf->logic_type);
	free(fd()->conf->instr);
}
