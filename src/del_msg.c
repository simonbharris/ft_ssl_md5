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

void	del_msg(t_msg **msg)
{
	ft_memdel((void**)&((*msg)->contents));
	free((*msg));
	*msg = NULL;
}
