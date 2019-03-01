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
	while (*new_len % 64 != 56)
		*new_len += 1;
	msg = (unsigned char *)malloc(sizeof(unsigned char) * (*new_len + 8));
	ft_bzero(msg, *new_len + 8);
	ft_memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = (unsigned char)128;
	bits_len = swap_endian_uint64(initial_len * 8);
	ft_memcpy(msg + *new_len, &bits_len, 8);
	return (msg);
}

static char				*sha224tostr(unsigned int hashbuff[8])
{
	char	*out;
	int		i;
	uint8_t	*p;
	int		j;

	i = 0;
	out = ft_strnew(56 + 1);
	while (i < 7)
	{
		p = (uint8_t *)&hashbuff[i];
		j = 0;
		while (j < 4)
		{
			out[i * 8 + j * 2] = quartet_to_hex((p[3 - j] >> 4));
			out[i * 8 + j * 2 + 1] = quartet_to_hex(p[3 - j]);
			j++;
		}
		i++;
	}
	return (out);
}

static void				init_hash(unsigned int h[8])
{
	h[0] = 0xc1059ed8;
	h[1] = 0x367cd507;
	h[2] = 0x3070dd17;
	h[3] = 0xf70e5939;
	h[4] = 0xffc00b31;
	h[5] = 0x68581511;
	h[6] = 0x64f98fa7;
	h[7] = 0xbefa4fa4;
}


/*
** Uses the process_sha256 because it is an identical algorithm to 224,
** 224 only has different starting hashes and omit h7 from output.
** which are both handled in this file. 
*/

char					*ft_sha224(t_msg *initial_msg)
{
	unsigned int	h[8];
	size_t			new_len;
	unsigned char	*msg;
	char			*digest;

	init_hash(h);
	msg = expand_msg(initial_msg->contents, initial_msg->len, &new_len);
	process_sha256(msg, new_len, h);
	digest = sha224tostr(h);
	free(msg);
	return (digest);
}
