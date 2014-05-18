/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboulet <jboulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:56:42 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/11 16:27:09 by jboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			ft_parser(char *str, t_conf *conf)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_instr_split(str, conf);
	conf->nb_instr = ft_count_instr(str);
	conf->instr = (t_instr**)malloc(sizeof(t_instr*) * conf->nb_instr);
	conf->logic_type = (int*)malloc(sizeof(int) * conf->nb_instr);
	while (i < conf->nb_instr)
	{
		conf->instr[i] = (t_instr*)malloc(sizeof(t_instr) * conf->nb_instr);
		ft_parse_instr(tmp[i], conf, i);
		conf->logic_type[i] = ft_get_logic_type(str, i);
		i++;
	}
	i = 0;
	while (i < conf->nb_instr)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void			ft_parse_instr(char *str, t_conf *c, int i)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_pipe_split(str);
	c->instr[i]->nb_cmd = ft_count_pipe(str) + 1;
	c->instr[i]->cmds = (t_cmd**)malloc(sizeof(t_cmd*) * c->instr[i]->nb_cmd);
	while (j < c->instr[i]->nb_cmd)
	{
		c->instr[i]->cmds[j] = (t_cmd*)malloc(sizeof(t_cmd));
		tmp[j] = ft_clean_instr(tmp[j]);
		ft_parse_cmd(tmp[j], c->instr[i]->cmds[j], j, c->instr[i]->nb_cmd);
		j++;
	}
	free(tmp);
}

char			*ft_clean_instr(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (&str[i]);
}

int				ft_get_instr_nb(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void			ft_free_tmp(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	if (tmp)
		free(tmp);
}
