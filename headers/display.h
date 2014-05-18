/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:18:16 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/10 11:45:27 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include <term.h>
# include <signal.h>

/*
** Dirent struct
*/
typedef struct dirent		t_dirent;

/*
** Sigaction struct
*/
typedef struct sigaction	t_sig;

/*
** String struct
*/
typedef struct				s_str
{
	char					c;

	struct s_str			*next;
	struct s_str			*prev;

}							t_str;

/*
** Terminal struct
*/
typedef struct				s_term
{
	int						col;
	int						row;

}							t_term;

/*
** Activ struct
*/
typedef struct				s_activ
{
	int						esc;
	int						in_history;

}							t_activ;

/*
** History struct
*/
typedef struct				s_hist
{
	char					*line;
	char					*backup_line;

	struct s_hist			*next;
	struct s_hist			*prev;

}							t_hist;

/*
** Autocompletion struct
*/
typedef struct				s_autoc
{
	char					*base;
	char					*last;
	int						rank;

}							t_autoc;

/*
** General struct
*/
typedef struct				s_gen
{
	struct termios			s_save;
	struct termios			s_term;
	char					**env;

	char					*prompt;

	char					*line;
	char					*backup_line;
	long					cursor_pos;

	t_autoc					autoc;

	t_activ					activ;
	t_term					terminal;

	t_hist					*actual_hist;
	t_hist					*first_hist;

}							t_gen;

/*
** 42sh.c
*/
t_gen						*g(void);
void						init_activ(void);
void						launch_42sh(char **env);

/*
** errors.c
*/
void						ft_error(char *str);

/*
** termcaps_functions.c
*/
void						get_termcap(void);
void						restore_termcap(void);
void						clean_termcap(void);
void						refresh_term(void);

/*
** move_termcaps.c
*/
void						move_up(void);
void						move_down(void);
void						move_left(void);
void						move_right(void);

/*
** move_termcaps_long.c
*/
void						move_up_long(int len);
void						move_down_long(int len);
void						move_left_long(int len);
void						move_right_long(int len);

/*
** key_manager.c
*/
int							key_manager(char *keytab);

/*
** is_key_0.c
*/
int							is_key_ctrl_d(char *keytab);
int							is_key_ctrl_r(char *keytab);
int							is_key_tab(char *keytab);
int							is_key_home(char *keytab);
int							is_key_end(char *keytab);

/*
** is_key_1.c
*/
int							is_key_up_arrow(char *keytab);
int							is_key_down_arrow(char *keytab);
int							is_key_left_arrow(char *keytab);
int							is_key_right_arrow(char *keytab);
int							is_key_return(char *keytab);

/*
** is_key_2.c
*/
int							is_key_pup(char *keytab);
int							is_key_pdown(char *keytab);
int							is_key_delete(char *keytab);
int							is_key_delete_right(char *keytab);
int							is_key_esc(char *keytab);

/*
** is_key_3.c
*/
int							is_key_shift_up(char *keytab);
int							is_key_shift_down(char *keytab);
int							is_key_shift_left(char *keytab);
int							is_key_shift_right(char *keytab);
int							is_key_esc_char(char *keytab);

/*
** micro_functions_0.c
*/
int							tputs_putchar(int c);
void						add_char_to_line(char c);
void						backup_actual_line(void);
void						restore_line(void);
int							is_line_empty(char *str);

/*
** return_system.c
*/
void						return_system(void);

/*
** deletion_system.c
*/
void						deletion_system_left(void);
void						deletion_system_right(void);
void						delete_len_left(int len);
void						delete_len_right(int len);

/*
** arrow_system.c
*/
void						left_arrow_system(void);
void						right_arrow_system(void);
void						up_arrow_system(void);
void						down_arrow_system(void);

/*
** arrow_system_long.c
*/
void						left_arrow_system_long(int len);
void						right_arrow_system_long(int len);

/*
** line_system.c
*/
void						rewrite_from(int from);
void						line_add_str(char *str);
void						line_add_char(char c);
void						line_del_char_left(void);
void						line_del_char_right(void);

/*
** special_key_system.c
*/
void						cursor_on_prompt(void);
void						cursor_at_end(void);
void						page_up(void);
void						page_down(void);

/*
** history_system.c
*/
void						backup_history_line(void);
void						restore_history_lines(void);
void						add_to_history(char *line);

/*
** infos_line_system.c
*/
int							get_size_left_word(void);
int							get_size_right_word(void);

/*
** big_screen_system.c
*/
int							big_screen_system(int real_curs, int virtual_pos);

/*
** cursor_manager.c
*/
void						cursor_system(char *keytab);
void						extract_pos_curs(void);
void						refresh_curs_pos(void);

/*
** signals.c
*/
void						get_signals(void);
void						handle_signal(int sig, siginfo_t *s, void *c);
void						ft_windows_size(void);

#endif
