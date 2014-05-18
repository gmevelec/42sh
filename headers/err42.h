/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err42.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 08:09:45 by zsarour           #+#    #+#             */
/*   Updated: 2014/03/04 19:28:14 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR42_H
# define ERR42_H

# define ERR42_RIGHTS 1
# define ERR42_LSEEK 2
# define ERR42_CREAT 3
# define ERR42_OPEN 4
# define ERR42_CLOSE 5
# define ERR42_FORK 6
# define ERR42_PIPE 7
# define ERR42_DUP2 8
# define ERR42_EXECVE 9
# define ERR42_MALLOC 10
# define ERR42_GETENV 11
# define ERR42_GATTR 12
# define ERR42_SATTR 13
# define ERR42_FILEIN 14
# define ERR42_CMDNOTFOUND 15
# define ERR42_NOPATH 16

/*
** err42.c
*/
void			ft_errors(short err);
void			ft_errors_2(short err);

#endif
