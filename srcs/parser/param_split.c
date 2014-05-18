/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboulet <jboulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 15:13:28 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/03 17:46:19 by jboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

static int		ft_count_param(const char *s)
{
	int		i;
	int		count;
	int		quote;

	i = 0;
	count = 0;
	quote = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] && s[i] != ' ' && !quote)
		{
			count++;
		}
		if (s[i] == '"')
			quote = (quote) ? 0 : 1;
		while (s[i] && s[i] != ' ')
		{
			if (s[i] == '"')
				quote = (quote) ? 0 : 1;
			i++;
		}
	}
	return (count);
}

static void		ft_check_param(int *i, const char *s, t_word *word_cut)
{
	while (s[*i])
	{
		ft_quote(s[*i]);
		if (s[*i] && s[*i] == ' ' && !ft_quote(0))
			break ;
		*i += 1;
		word_cut->length++;
	}
}

char			**ft_param_split(const char *s)
{
	char	**str_tab;
	int		i;
	int		c_word;
	t_word	word_cut;

	if (s == NULL)
		return (NULL);
	i = 0;
	c_word = 0;
	word_cut.nb = ft_count_param(s) + 1;
	str_tab = malloc(sizeof(char*) * (word_cut.nb + 1));
	while (s[i] && c_word < word_cut.nb)
	{
		word_cut.length = 1;
		ft_quote(s[i]);
		word_cut.start = i++;
		ft_check_param(&i, s, &word_cut);
		str_tab[c_word] = ft_strsub(s, word_cut.start, word_cut.length);
		i++;
		c_word++;
	}
	str_tab[c_word] = NULL;
	return (str_tab);
}

int				ft_quote(char c)
{
	static int		quote;

	if (c == '"')
	{
		quote = (quote) ? 0 : 1;
	}
	return (quote);
}
