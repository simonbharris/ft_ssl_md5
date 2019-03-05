/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 02:58:47 by sharris           #+#    #+#             */
/*   Updated: 2019/02/25 02:58:49 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** both t_msg and the char* are going to be alloced.
** Delete them in order.
*/

void	del_msg(t_msg **msg)
{
	ft_memdel((void**)&((*msg)->contents));
	free((*msg));
	*msg = NULL;
}
