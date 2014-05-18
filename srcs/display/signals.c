/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 16:21:36 by crenault          #+#    #+#             */
/*   Updated: 2014/03/26 18:05:57 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <signal.h>
#include <sys/ioctl.h>
#include <term.h>

void			get_signals(void)
{
	t_sig		sig_s;

	sig_s.sa_sigaction = &handle_signal;
	sig_s.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGWINCH, &sig_s, NULL) == -1)
		ft_error("Sigaction");
	if (sigaction(SIGTSTP, &sig_s, NULL) == -1)
		ft_error("Sigaction");
	if (sigaction(SIGINT, &sig_s, NULL) == -1)
		ft_error("Sigaction");
	if (sigaction(SIGCONT, &sig_s, NULL) == -1)
		ft_error("Sigaction");
}

static void		new_prompt(int jump)
{
	restore_history_lines();
	if (g()->activ.in_history)
		g()->activ.in_history = FALSE;
	cursor_at_end();
	if (jump)
		move_down();
	ft_strdel(&g()->line);
	g()->line = ft_strnew(1);
	ft_strclr(g()->line);
	g()->cursor_pos = 0;
	ft_putstr(g()->prompt);
}

void			handle_signal(int sig, siginfo_t *s, void *c)
{
	char		str[2];

	(void)s;
	(void)c;
	str[0] = g()->s_term.c_cc[VSUSP];
	str[1] = 0;
	if (sig == SIGWINCH)
		ft_windows_size();
	if (sig == SIGINT)
		new_prompt(TRUE);
	if (sig == SIGCONT)
		new_prompt(FALSE);
	if (sig == SIGTSTP)
	{
		ioctl(0, TIOCSTI, str);
		signal(SIGTSTP, SIG_DFL);
	}
}

void			ft_windows_size(void)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	g()->terminal.row = (w.ws_row < 1) ? 1 : w.ws_row;
	g()->terminal.col = (w.ws_col < 1) ? 1 : w.ws_col;
}
