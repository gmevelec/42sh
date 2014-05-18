/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion_system_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:18:59 by crenault          #+#    #+#             */
/*   Updated: 2014/03/05 17:59:33 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/sh42.h"
#include <dirent.h>
#include <term.h>

static void		get_actual_base(void)
{
	int			len;
	int			len_word;

	if ((g()->cursor_pos > 0 && g()->line[g()->cursor_pos - 1] == ' ' &&
		g()->line[g()->cursor_pos] == ' '))
		g()->autoc.base = NULL;
	else
	{
		len = 0;
		if (g()->line[g()->cursor_pos - 1] != ' ')
			len = get_size_left_word();
		if (len == 0)
			right_arrow_system();
		else
			left_arrow_system_long(len);
		len_word = get_size_right_word();
		g()->autoc.base = ft_strsub(g()->line, g()->cursor_pos, len_word);
		if (g()->autoc.base[0] == ' ')
			g()->autoc.base++;
		if (!ft_strlen(g()->autoc.base))
			g()->autoc.base = NULL;
		right_arrow_system_long(len);
		if (ft_strlen(g()->autoc.base) == 1 && g()->autoc.base[0] == '/')
			g()->autoc.base = NULL;
	}
}

static void		get_path_and_name(char **path, char **name)
{
	char		*last_bslash;
	int			len_path;
	int			i;

	i = 0;
	if (ft_strlen(g()->autoc.base))
	{
		last_bslash = ft_strrchr(g()->autoc.base, '/');
		if (last_bslash)
		{
			last_bslash++;
			*name = ft_strdup(last_bslash);
		}
		else
			*name = ft_strdup(g()->autoc.base);
		if (g()->autoc.base[ft_strlen(g()->autoc.base) - 1] == '/')
			ft_strdel(name);
		len_path = ft_strlen(g()->autoc.base) - ft_strlen(*name);
		if (len_path)
			*path = ft_strsub(g()->autoc.base, 0, len_path);
		if (!len_path || !ft_strlen(*path) || g()->autoc.base == NULL)
			*path = ft_strdup("./");
	}
}

static int		nbr_match(char *path, char *filename)
{
	DIR			*directory;
	t_dirent	*file;
	int			i;

	i = 0;
	directory = opendir(path);
	if (directory)
	{
		while ((file = readdir(directory)))
		{
			if (!ft_strncmp(filename, file->d_name, ft_strlen(filename)) &&
				ft_strcmp(".", file->d_name) && ft_strcmp("..", file->d_name))
				i++;
		}
		closedir(directory);
	}
	return (i);
}

static char		*get_next_word(char *path, char *name, int nbr_matching)
{
	DIR			*directory;
	t_dirent	*file;
	char		**matching;
	int			i;

	i = 0;
	matching = (char **)malloc(sizeof(char *) * nbr_matching);
	if ((directory = opendir(path)))
	{
		while ((file = readdir(directory)))
		{
			if (!ft_strncmp(name, file->d_name, ft_strlen(name)) &&
				ft_strcmp(".", file->d_name) && ft_strcmp("..", file->d_name))
			{
				matching[i] = ft_strdup(file->d_name);
				if (file->d_type == DT_DIR)
					ft_strcat(matching[i], "/");
				i++;
			}
		}
		closedir(directory);
	}
	if (nbr_matching)
		return (matching[(g()->autoc.rank % nbr_matching)]);
	return (NULL);
}

void			autocomplete_word(void)
{
	char			*next_arg;
	char			*name;
	char			*path;

	if (g()->autoc.rank == -1)
		get_actual_base();
	get_path_and_name(&path, &name);
	autocompletion_activ(TRUE);
	left_arrow_system_long(get_size_left_word());
	right_arrow_system_long(get_size_right_word() + 1);
	if (g()->autoc.last)
		delete_len_left(ft_strlen(g()->autoc.last));
	else
		delete_len_left(ft_strlen(name));
	g()->autoc.last = get_next_word(path, name, nbr_match(path, name));
	if (g()->autoc.last)
		line_add_str(g()->autoc.last);
	else
	{
		if (name)
			line_add_str(name);
		tputs(tgetstr("bl", NULL), 1, tputs_putchar);
	}
	if (nbr_match(path, name) == 1)
		autocompletion_activ(FALSE);
}
