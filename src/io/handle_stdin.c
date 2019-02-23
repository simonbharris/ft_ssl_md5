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
	char		*contents;
	char		buffer[SSL_READ_BUFFSIZE];
	char		*tmp;
	ssize_t		ret;

	contents = NULL;
	while ((ret = read(0, buffer, SSL_READ_BUFFSIZE)) > 0)
	{
		buffer[ret] = 0;
		tmp = contents;
		contents = ft_strjoin(contents, buffer);
		free(tmp);
	}
	if (g_ft_ssl_flags & FTSSL_P)
		ft_printf("%s", contents);
	ft_printf("%s\n", (tmp = ssl_f->funct(contents)));
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&contents);
}
