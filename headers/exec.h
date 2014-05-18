/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:08:20 by zsarour           #+#    #+#             */
/*   Updated: 2014/02/28 13:08:20 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef struct		s_fd
{
	int				i;
	int				**fd;
	int				stdin;
	int				stdout;
	int				nb_cmds;
	int				nb_para;
	int				out_type;
	int				nb_forks;
	char			**cmds;
	char			**paths;
	char			*file_in;
	char			*file_out;
	t_conf			*conf;

}					t_fd;

/*
** srcs / exec / cmd.c
*/
short				exec_search_cmd(void);
short				exec_search_cmd_2(char *tmp_2);
short				exec_search_if_builtin_and_access(void);

/*
** srcs / exec / exec.c
*/
void				exec_42sh(char *cmd);
void				exec_launch_instr(t_conf conf, int *i);
void				exec_is_cmd(int is_cmd, int *j);

/*
** srcs / exec / exec_2.c
*/
void				exec_is_logic(int *i);
short				exec_do_execve(int i, int *j);
void				exec_read_and_print(int i);

/*
** srcs / exec / fd.c
*/
t_fd				*fd(void);
void				exec_malloc_fds(int nbr);
void				exec_init_struct_fd(t_instr instr, int i);
void				exec_close_fds(void);

/*
** srcs / exec / file.c
*/
int					exec_get_file_fd(int fd_file);
void				exec_clear_file(int fd);
void				exec_read_file_in(char *file);

/*
** srcs / exec / free.c
*/
void				exec_free_all(void);

/*
** srcs / exec / paths.c
*/
void				exec_get_paths(void);
char				**exec_split_paths(char *env);
int					exec_count_paths(char *env);
char				*exec_strcpy_paths(char **s1, char *s2, int i);

/*
** srcs / exec / pipe.c
*/
void				exec_cmd(int i);
void				exec_cmd_father(int i);
void				exec_cmd_son(int i);

#endif
