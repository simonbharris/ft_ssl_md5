/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:37:17 by sharris           #+#    #+#             */
/*   Updated: 2019/02/21 20:37:27 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static char	*md5tostr(unsigned int hashbuff[4])
{
	char	*out;
	int		i;
	uint8_t	*p;
	int		j;

	i = 0;
	out = ft_strnew(32);
	while (i < 4)
	{
		p = (uint8_t *)&hashbuff[i];
		j = -1;
		while (++j < 4)
		{
			out[i * 8 + j * 2] = quartet_to_hex((p[j] >> 4));
			out[i * 8 + j * 2 + 1] = quartet_to_hex(p[j]);
		}
		i++;
	}
	return (out);
}

char		*ft_md5(t_msg *msg)
{
	char			*out;
	unsigned int	hash_buffer[4];

	process_md5(msg->contents, msg->len, hash_buffer);
	out = md5tostr(hash_buffer);
	return (out);
}
