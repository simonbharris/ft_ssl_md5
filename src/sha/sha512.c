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

static unsigned char	*expand_msg(uint8_t *initial_msg,
	size_t initial_len, size_t *new_len)
{
	unsigned char	*msg;
	uint64_t		bits_len;

	*new_len = initial_len;
	*new_len += 1;
	while (*new_len % 128 != 120)
		*new_len += 1;
	msg = ft_memalloc(sizeof(unsigned char) * (*new_len + 8));
	ft_memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = (unsigned char)128;
	bits_len = swap_endian_uint64(initial_len * 8);
	ft_memcpy(msg + *new_len, &bits_len, 8);
	return (msg);
}

static char				*sha512tostr(uint64_t hashbuff[8])
{
	char	*out;
	int		i;
	uint8_t	*p;
	int		j;

	i = 0;
	out = ft_strnew(128 + 1);
	while (i < 8)
	{
		p = (uint8_t *)&hashbuff[i];
		j = 0;
		while (j < 8)
		{
			out[i * 16 + j * 2] = quartet_to_hex((p[7 - j] >> 4));
			out[i * 16 + j * 2 + 1] = quartet_to_hex(p[7 - j]);
			j++;
		}
		i++;
	}
	return (out);
}

static void				init_hash(uint64_t h[8])
{
	h[0] = 0x6a09e667f3bcc908;
	h[1] = 0xbb67ae8584caa73b;
	h[2] = 0x3c6ef372fe94f82b;
	h[3] = 0xa54ff53a5f1d36f1;
	h[4] = 0x510e527fade682d1;
	h[5] = 0x9b05688c2b3e6c1f;
	h[6] = 0x1f83d9abfb41bd6b;
	h[7] = 0x5be0cd19137e2179;
}

char					*ft_sha512(t_msg *initial_msg)
{
	uint64_t			h[8];
	size_t				new_len;
	unsigned char		*msg;
	char				*digest;

	init_hash(h);
	msg = expand_msg(initial_msg->contents, initial_msg->len, &new_len);
	process_sha512(msg, new_len, h);
	digest = sha512tostr(h);
	free(msg);
	return (digest);
}
