/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboulet <jboulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:21:05 by jboulet           #+#    #+#             */
/*   Updated: 2014/03/11 13:53:42 by jboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

int				ft_count_pipe(const char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '|' && s[i + 1] && s[i + 1] != '|')
		{
			if (i > 0 && s[i - 1] != '|')
			{
				count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

static void		ft_check_pipe(int *i, const char *s, t_word *word_cut)
{
	while (s[*i])
	{
		if (s[*i] && s[*i] == '|' && s[*i + 1] != '|')
		{
			if (*i > 0 && s[*i - 1] != '|')
			{
				break ;
			}
		}
		*i += 1;
		word_cut->length++;
	}
}

char			**ft_pipe_split(const char *s)
{
	char	**str_tab;
	int		i;
	int		c_word;
	t_word	word_cut;

	if (s == NULL)
		return (NULL);
	i = 0;
	c_word = 0;
	word_cut.nb = ft_count_pipe(s) + 1;
	str_tab = (char**)malloc(sizeof(char*) * (word_cut.nb + 1));
	while (s[i] && c_word < word_cut.nb)
	{
		word_cut.length = 1;
		word_cut.start = i++;
		ft_check_pipe(&i, s, &word_cut);
		str_tab[c_word] = ft_strsub(s, word_cut.start, word_cut.length);
		i++;
		c_word++;
	}
	str_tab[c_word] = NULL;
	return (str_tab);
}
