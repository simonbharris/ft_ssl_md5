/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_endian_uint64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:35:48 by sharris           #+#    #+#             */
/*   Updated: 2019/02/21 20:35:55 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts the endianness of a 64 bit integer.
*/

unsigned long long	swap_endian_uint64(long long bits)
{
	return (
		((bits & 0xff00000000000000ULL) >> 56) |
		((bits & 0x00ff000000000000ULL) >> 40) |
		((bits & 0x0000ff0000000000ULL) >> 24) |
		((bits & 0x000000ff00000000ULL) >> 8) |
		((bits & 0x00000000ff000000ULL) << 8) |
		((bits & 0x0000000000ff0000ULL) << 24) |
		((bits & 0x000000000000ff00ULL) << 40) |
		((bits & 0x00000000000000ffULL) << 56));
}
