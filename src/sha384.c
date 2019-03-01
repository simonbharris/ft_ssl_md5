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

static char				*sha384tostr(unsigned long long hashbuff[8])
{
	char	*out;
	int		i;
	uint8_t	*p;
	int		j;

	i = 0;
	out = ft_strnew(128 + 1);
	while (i < 6)
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

static void				init_hash(unsigned long long h[8])
{
	h[0] = 0xcbbb9d5dc1059ed8;
	h[1] = 0x629a292a367cd507;
	h[2] = 0x9159015a3070dd17;
	h[3] = 0x152fecd8f70e5939;
	h[4] = 0x67332667ffc00b31;
	h[5] = 0x8eb44a8768581511;
	h[6] = 0xdb0c2e0d64f98fa7;
	h[7] = 0x47b5481dbefa4fa4;
}

/*
** SHA512 and SHA384 use the same processing algorithm, only differing init_hash and to string.
*/

char					*ft_sha384(t_msg *initial_msg)
{
	unsigned long long	h[8];
	size_t			new_len;
	unsigned char	*msg;
	char			*digest;

	init_hash(h);
	msg = expand_msg(initial_msg->contents, initial_msg->len, &new_len);
	process_sha512(msg, new_len, h);
	digest = sha384tostr(h);
	free(msg);
	return (digest);
}
