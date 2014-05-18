/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsarour <zsarour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:24:35 by zsarour           #+#    #+#             */
/*   Updated: 2014/02/27 16:24:35 by zsarour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

typedef struct	s_status
{
	int			status;

}				t_status;

/*
** srcs / status / status.c
*/
t_status		*status(void);
short			builtin_last_return(char *cmd);

#endif
