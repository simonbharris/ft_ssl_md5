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

# include <ft_ssl.h>

// TODO: Make this modular, have the size of array passed and use it to define str length and iterations of i
static char *md5tostr(unsigned int hashbuff[4])
{
	char *out;
	int i;
	uint8_t *p;

	i = 0;
	out = ft_strnew(32);
	while (i < 4)
	{
		p = (uint8_t *)&hashbuff[i];
		for (int j = 0; j < 4; j++)
		{
			out[i * 8 + j * 2] = quartet_to_hex((p[j] >> 4));
			out[i * 8 + j * 2 + 1] = quartet_to_hex(p[j]);
		}
		i++;
	}
	return (out);
}

// Use this to extract the MD5
char *ft_md5(char *msg)
{
	size_t len;
	char *out;
	unsigned int hash_buffer[4];

	len = ft_strlen(msg);
	process_md5((uint8_t *)msg, len, hash_buffer);
	out = md5tostr(hash_buffer);
	return (out);
}
