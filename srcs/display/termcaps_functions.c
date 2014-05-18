/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:12:32 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 15:04:02 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <term.h>

void			get_termcap(void)
{
	char		*term_env;

	term_env = ft_getenv("TERM=", g()->env);
	if (tgetent(NULL, term_env) < 1)
	{
		ft_errors(ERR42_GETENV);
		ft_putendl("exit");
		_exit(100);
	}
	if (tcgetattr(STDIN_FILENO, &(g()->s_save)) != 0)
		ft_errors(ERR42_GATTR);
	g()->s_term = g()->s_save;
	g()->s_term.c_lflag &= ~(ICANON | ECHO);
	g()->s_term.c_lflag |= ISIG;
	g()->s_term.c_cc[VMIN] = 1;
	g()->s_term.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &(g()->s_term)) != 0)
		ft_errors(ERR42_SATTR);
	ft_strdel(&term_env);
}

void			refresh_term(void)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &(g()->s_term)) != 0)
		ft_errors(ERR42_SATTR);
}

void			clean_termcap(void)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &(g()->s_save)) != 0)
		ft_errors(ERR42_SATTR);
}
