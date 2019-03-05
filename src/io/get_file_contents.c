/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_contents.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 20:58:37 by sharris           #+#    #+#             */
/*   Updated: 2019/02/28 20:58:38 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** Reads file as bytes and retains the length into a struct.
*/

t_msg	*get_file_contents(char *file)
{
	int				fd;
	int				ret;
	t_msg			*msg;
	char			buff[SSL_READ_BUFFSIZE];
	unsigned char	*tmp;

	msg = NULL;
	if ((fd = open(file, O_RDONLY)) > 0)
	{
		msg = init_msg();
		while ((ret = read(fd, buff, SSL_READ_BUFFSIZE)))
		{
			tmp = msg->contents;
			msg->contents = ft_memalloc(msg->len + ret);
			ft_memcpy(msg->contents, tmp, msg->len);
			ft_memcpy(msg->contents + msg->len, buff, ret);
			msg->len += ret;
			free(tmp);
		}
	}
	else
		ft_printf("ft_ssl: %s: Error, check file name and permissions\n", file);
	return (msg);
}
