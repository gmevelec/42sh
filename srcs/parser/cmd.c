/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:50:09 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/24 19:17:26 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

void			ft_parse_cmd(char *str, t_cmd *cmd, int j, int nb)
{
	char	**tmp;

	cmd->file_in = ft_find_file_in(str);
	cmd->file_out = ft_find_file_out(str, cmd);
	if (cmd->file_out || cmd->file_in)
		ft_clean_cmd(str);
	if (ft_strlen(str))
	{
		tmp = ft_param_split(str);
		cmd->name = ft_strdup(tmp[0]);
		cmd->param = tmp;
		cmd->param_nb = ft_get_instr_nb(cmd->param);
	}
	else
	{
		cmd->name = NULL;
		cmd->param = NULL;
		cmd->param_nb = 0;
	}
	cmd->pipe_in = (j > 0) ? 1 : 0;
	cmd->pipe_out = (j < nb - 1) ? 1 : 0;
}

void			ft_clean_cmd(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}

char			*ft_find_file_in(char *str)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (str[i])
	{
		if (found && ft_isalnum(str[i]))
			return (str + i);
		else if (str[i] == '<')
			found = 1;
		i++;
	}
	return (NULL);
}

char			*ft_find_file_out(char *str, t_cmd *cmd)
{
	int		i;
	int		found;

	i = 0;
	found = -1;
	while (str[i])
	{
		if (found >= 0 && ft_isalnum(str[i]))
			return (str + i);
		else if (!ft_strncmp(&str[i], ">>", 2))
		{
			found = i;
			cmd->out_type = 2;
			i += 2;
		}
		else if (str[i] == '>')
		{
			found = i;
			cmd->out_type = 1;
			i++;
		}
		else
			i++;
	}
	return (NULL);
}
