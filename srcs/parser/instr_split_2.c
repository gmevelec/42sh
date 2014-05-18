/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_split_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:29:39 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 17:29:39 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

static int		ft_check_instr(int *i, const char *s, t_word *word_cut, int *lo)
{
	while (s[*i])
	{
		ft_quote(s[*i]);
		if (s[*i] && ft_is_separator(&s[*i]) && !ft_quote(0))
		{
			if (!ft_strncmp(&s[*i], "||", 2) || !ft_strncmp(&s[*i], "&&", 2))
			{
				if (!ft_strncmp(&s[*i], "||", 2))
					*lo = 1;
				else
					*lo = 2;
				return (2);
			}
			*lo = 0;
			return (1);
		}
		*i += 1;
		word_cut->length++;
	}
	*lo = 0;
	return (0);
}

char			**ft_instr_split(const char *s, t_conf *conf)
{
	char	**str_tab;
	int		i;
	int		c_word;
	t_word	word_cut;

	if (s == NULL)
		return (NULL);
	i = 0;
	c_word = 0;
	word_cut.nb = ft_count_instr(s) + 1;
	conf->logic_type = (int*)malloc(sizeof(int) * word_cut.nb);
	str_tab = malloc(sizeof(char*) * (word_cut.nb + 1));
	while (s[i] && c_word < word_cut.nb)
	{
		word_cut.length = 1;
		ft_quote(s[i]);
		word_cut.start = i++;
		i += ft_check_instr(&i, s, &word_cut, &conf->logic_type[c_word]);
		str_tab[c_word] = ft_strsub(s, word_cut.start, word_cut.length);
		c_word++;
	}
	str_tab[c_word] = NULL;
	return (str_tab);
}
