/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sha256.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:36:30 by sharris           #+#    #+#             */
/*   Updated: 2019/02/21 20:36:33 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>
#include <stdio.h>

static const int g_sha256_k[] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static unsigned int		getword(unsigned char *msg, int offset)
{
	unsigned int	out;
	int				i;

	i = -1;
	out = 0;
	while(++i < 4)
		out |= msg[offset + i] << (24 - i * 8);
	return (out);
}

static unsigned char	*expand_msg(uint8_t *initial_msg, size_t initial_len, size_t *new_len)
{
	unsigned char	*msg;
	uint64_t		bits_len;

	*new_len = initial_len;
	*new_len += 1;
	while (*new_len % 64 != 56)
		*new_len += 1;
	msg = (unsigned char *)malloc(sizeof(unsigned char) * (*new_len + 8));
	ft_bzero(msg, *new_len+8);
	ft_memcpy(msg, initial_msg, initial_len);
	msg[initial_len] = (unsigned char) 128;
	bits_len = swap_endian_uint64(initial_len * 8);
	ft_memcpy(msg + *new_len, &bits_len, 8);
	return (msg);
}

static void				load_chunk(unsigned int w[64], unsigned char *msg, int offset)
{
	int i;

	i = 0;
	while (offset + i < offset + 64)
	{
		if (i < 16)
			w[i] = getword(msg, offset + i * 4);
		else
		{
			int s0 = RIGHTROTATE(w[i - 15], 7) ^ RIGHTROTATE(w[i - 15], 18) ^ (w[i - 15] >> 3);
			int s1 = RIGHTROTATE(w[i - 2], 17) ^ RIGHTROTATE(w[i - 2], 19) ^ (w[i - 2] >> 10);
			w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		}
		i++;
	}
}

static void				process_chunk(unsigned int ah[8], unsigned int w[64])
{
	unsigned int tmp1;
	unsigned int tmp2;
	int i;

	i = 0;
	while (i < 64)
	{
		tmp1 = ah[7] + EP1(ah[4]) + CH(ah[4],ah[5],ah[6]) + g_sha256_k[i] + w[i];
		tmp2 = EP0(ah[0]) + MAJ(ah[0],ah[1],ah[2]);
		ah[7] = ah[6];
		ah[6] = ah[5];
		ah[5] = ah[4];
		ah[4] = ah[3] + tmp1;
		ah[3] = ah[2];
		ah[2] = ah[1];
		ah[1] = ah[0];
		ah[0] = tmp1 + tmp2;
		i++;
	}
}

void					process_sha256(char *initial_msg, unsigned int h[8])
{
	unsigned int	ah[8];
	unsigned int	w[64];
	unsigned char	*msg;
	size_t			new_len;
	int				offset;

	offset = 0;
	msg = expand_msg((uint8_t *)initial_msg, ft_strlen(initial_msg), &new_len);
	while (offset < new_len)
	{
		int i;

		load_chunk(w, msg, offset);
		i = -1;
		while (++i < 8)
			ah[i] = h[i];
		process_chunk(ah, w);
		i = -1;
		while (++i < 8)
			h[i] += ah[i];
		offset += 64;
	}
	free(msg);
}
