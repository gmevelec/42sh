/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:18:42 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 17:18:42 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

t_gen			*g(void)
{
	static t_gen	*gen = NULL;

	if (gen == NULL)
		gen = (t_gen *)malloc(sizeof(t_gen));
	return (gen);
}

void			init_activ(void)
{
	g()->activ.esc = FALSE;
	g()->activ.in_history = FALSE;
	g()->autoc.rank = -1;
	g()->autoc.last = NULL;
	g()->actual_hist = NULL;
	g()->first_hist = NULL;
}

static void		init_shell(char **env)
{
	static char		prompt[] = {"\033[0mschtroumpf$> "};

	g()->env = env;
	get_termcap();
	g()->line = ft_strnew(1);
	ft_strclr(g()->line);
	g()->prompt = ft_strdup(prompt);
	g()->cursor_pos = 0;
	ft_windows_size();
	get_signals();
	init_activ();
}

void			launch_42sh(char **env)
{
	char		*read_key;
	int			read_len;

	read_key = (char *)malloc(sizeof(char) * 5);
	init_shell(env);
	ft_putstr(g()->prompt);
	ft_strclr(read_key);
	while ((read_len = read(0, read_key, 4)) > 0)
	{
		key_manager(read_key);
		ft_strclr(read_key);
	}
}
