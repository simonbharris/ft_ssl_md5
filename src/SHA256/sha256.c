/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:36:40 by sharris           #+#    #+#             */
/*   Updated: 2019/02/21 20:36:49 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static char *sha256tostr(unsigned int hashbuff[8])
{
	char *out;
	int i;
	uint8_t *p;

	i = 0;
	out = ft_strnew(64);
	while (i < 8)
	{
		p = (uint8_t *)&hashbuff[i];
		for (int j = 0; j < 4; j++)
		{
			out[i * 8 + j * 2] = quartet_to_hex((p[3-j] >> 4));
			out[i * 8 + j * 2 + 1] = quartet_to_hex(p[3-j]);
		}
		i++;
	}
	return (out);
}

static void init_hash(unsigned int h[8])
{
	h[0] = 0x6a09e667;
	h[1] = 0xbb67ae85;
	h[2] = 0x3c6ef372;
	h[3] = 0xa54ff53a;
	h[4] = 0x510e527f;
	h[5] = 0x9b05688c;
	h[6] = 0x1f83d9ab;
	h[7] = 0x5be0cd19;
}


char *ft_sha256(char *initial_msg)
{
	unsigned int h[8];

	init_hash(h);
	process_sha256(initial_msg, h);
	char *digest = sha256tostr(h);
	return (digest);
}
