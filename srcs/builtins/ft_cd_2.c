/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:44:24 by gmevelec          #+#    #+#             */
/*   Updated: 2014/03/26 18:02:25 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"

char		**ft_cd_no_args(char **environ)
{
	char	*str;
	char	*pwd;
	char	**tab_t;

	pwd = ft_getenv("PWD=", environ);
	str = ft_getenv("HOME=", environ);
	tab_t = get_param("OLDPWD", pwd);
	environ = ft_setenv(tab_t, environ);
	tab_t = get_param("PWD", str);
	environ = ft_setenv(tab_t, environ);
	chdir(str);
	return (environ);
}

char		**ft_cd_back(char **environ)
{
	char	*str;
	char	*pwd;
	char	**tab_t;

	pwd = ft_getenv("OLDPWD=", environ);
	chdir(pwd);
	ft_putendl(pwd);
	str = ft_getenv("PWD=", environ);
	tab_t = get_param("OLDPWD", str);
	environ = ft_setenv(tab_t, environ);
	tab_t = get_param("PWD", pwd);
	environ = ft_setenv(tab_t, environ);
	return (environ);
}

char		**ft_cd_args(char **param, char **environ, char *pwd)
{
	char	*str;
	char	**tab_t;

	if (param[1][0] == '~')
	{
		str = ft_getenv("HOME=", environ);
		str = ft_strjoin(str, ++param[1]);
		chdir(str);
	}
	else
	{
		if (access(param[1], R_OK) == -1)
			ft_putstr("no such file or directory\n");
		else
		{
			chdir(param[1]);
			str = getwd(NULL);
			tab_t = get_param("OLDPWD", pwd);
			environ = ft_setenv(tab_t, environ);
			tab_t = get_param("PWD", str);
			environ = ft_setenv(tab_t, environ);
		}
	}
	return (environ);
}
