/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 02:59:13 by sharris           #+#    #+#             */
/*   Updated: 2019/02/25 02:59:14 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** A t_msg holds information about the message to digest.
** A length is retained in the event we read a null byte
** We cannot use functions that stop on null-terminated strings.
*/

t_msg	*init_msg(void)
{
	t_msg *new_msg;

	new_msg = ft_memalloc(sizeof(t_msg));
	new_msg->contents = NULL;
	new_msg->len = 0;
	return (new_msg);
}
