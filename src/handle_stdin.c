/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:36:17 by sharris           #+#    #+#             */
/*   Updated: 2019/02/21 20:36:18 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

void	handle_stdin(const t_ssl_f *ssl_f)
{
	t_msg			*msg;
	char			buffer[SSL_READ_BUFFSIZE];
	unsigned char	*tmp;
	ssize_t			ret;

	msg = init_msg();
	while ((ret = read(0, buffer, SSL_READ_BUFFSIZE)) > 0)
	{
		tmp = msg->contents;
		msg->contents = ft_memalloc(msg->len + ret);
		ft_memcpy(msg->contents, tmp, msg->len);
		ft_memcpy(msg->contents + msg->len, buffer, ret);
		msg->len += ret;
		ft_memdel((void **)&tmp);
	}
	if (g_ft_ssl_flags & FTSSL_P)
	{
		write(1, msg->contents, msg->len);
	}
	ft_printf("%s\n", (tmp = (unsigned char *)ssl_f->funct(msg)));
	ft_memdel((void **)&tmp);
	del_msg(&msg);
}
