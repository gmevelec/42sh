/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:13:42 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/24 16:17:58 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

typedef struct	s_ptr
{
	char	**(*func)();
	char	*name;

}				t_ptr;

/*
** ft_cd.c
*/
char			*ft_getenv(char *name, char **environ);
char			**ft_cd(char **param, char **environ);
char			**get_param(char *s1, char *s2);
/*
** ft_cd_2.c
*/
char			**ft_cd_no_args(char **environ);
char			**ft_cd_args(char **param, char **environ, char *pwd);
char			**ft_cd_back(char **environ);

/*
** ft_echo.c
*/
char			**ft_echo(char **param, char **environ);

/*
** ft_env.c
*/
char			**ft_env(char **param, char **environ);
void			ft_env_2(char **param, int i);

/*
** ft_exit.c
*/
char			**ft_exit(char **param, char **environ);

/*
** ft_unsetenv.c
*/
char			**ft_unsetenv(char **param, char **environ);

/*
** ft_setenv.c
*/
char			**ft_setenv(char **param, char **environ);

/*
** ft_duck.c
*/
char			**ft_duck(char **param, char **env);

/*
** ft_is_builtin.c
*/
char			**ft_newenv(char **environ);
int				ft_is_builtin(char **param, char **environ);

#endif
