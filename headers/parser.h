/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:23:19 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/27 05:19:32 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct		s_word
{
	int				start;
	int				length;
	int				nb;

}					t_word;

typedef struct		s_cmd
{
	char			*name;
	char			*file_in;
	char			*file_out;
	char			**param;
	int				param_nb;
	int				pipe_in;
	int				pipe_out;
	int				out_type;

}					t_cmd;

typedef struct		s_instr
{
	int				nb_cmd;
	t_cmd			**cmds;

}					t_instr;

typedef struct		s_conf
{
	int				nb_instr;
	int				*logic_type;
	t_instr			**instr;

}					t_conf;

/*
** cmd.c
*/
void				ft_parse_cmd(char *str, t_cmd *cmd, int j, int nb);
void				ft_logic_parse(char *str, t_cmd *cmd);
void				ft_clean_cmd(char *str);
char				*ft_find_file_in(char *str);
char				*ft_find_file_out(char *str, t_cmd *cmd);

/*
** instr_split.c
*/

/*
** instr_split_2.c
*/
char				**ft_instr_split(const char *s, t_conf *conf);

/*
** param_split.c
*/
char				**ft_param_split(const char *s);
int					ft_get_logic_type(const char *s, int nb);
void				ft_get_logic_type_2(int *i, int *quote, const char *s);

/*
** parser.c
*/
void				ft_parser(char *str, t_conf *conf);
void				ft_parse_instr(char *str, t_conf *c, int i);
char				*ft_clean_instr(char *str);
int					ft_get_instr_nb(char **str);
void				ft_free_tmp(char **tmp);

/*
** pipe_split.c
*/
int					ft_count_pipe(const char *s);
char				**ft_pipe_split(const char *s);
int					ft_quote(char c);
int					ft_is_separator(const char *str);
char				**ft_instr_split(const char *s, t_conf *conf);
int					ft_count_instr(const char *s);
#endif
