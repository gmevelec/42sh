/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboulet <jboulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 16:56:57 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/11 13:59:28 by jboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

int				ft_is_separator(const char *str)
{
	if (str && (str[0] == ';' || !ft_strncmp(str, "||", 2) ||
		!ft_strncmp(str, "&&", 2)))
	{
		return (1);
	}
	return (0);
}

int				ft_is_separator_type(const char *str)
{
	if (str && (str[0] == ';'))
		return (0);
	if (!ft_strncmp(str, "||", 2))
		return (1);
	if (!ft_strncmp(str, "&&", 2))
		return (2);
	return (0);
}

int				ft_count_instr(const char *s)
{
	int		i;
	int		count;
	int		quote;

	i = 0;
	count = 0;
	quote = 0;
	while (s[i])
	{
		while (s[i] && ft_is_separator(&s[i]))
			i++;
		if (s[i] && !ft_is_separator(&s[i]) && !quote)
			count++;
		if (!s[i + 1])
			count--;
		if (s[i] == '"')
			quote = (quote) ? 0 : 1;
		while (s[i] && !ft_is_separator(&s[i]))
		{
			if (s[i] == '"')
				quote = (quote) ? 0 : 1;
			i++;
		}
	}
	return (count);
}

int				ft_get_logic_type(const char *s, int nb)
{
	int		i;
	int		count;
	int		quote;
	int		type;

	i = 0;
	count = 0;
	quote = 0;
	type = 0;
	while (s[i])
	{
		if (nb == 0)
			return (type);
		while (s[i] && ft_is_separator(&s[i]))
			i++;
		if (s[i] == '"')
			quote = (quote) ? 0 : 1;
		ft_get_logic_type_2(&i, &quote, s);
		if (ft_is_separator(&s[i]))
		{
			type = ft_is_separator_type(&s[i]);
			nb--;
		}
	}
	return (count);
}

void			ft_get_logic_type_2(int *i, int *quote, const char *s)
{
	while (s[*i] && !ft_is_separator(&s[*i]))
	{
		if (s[*i] == '"')
			*quote = (*quote) ? 0 : 1;
		*i += 1;
	}
}
