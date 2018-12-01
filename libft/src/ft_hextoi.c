/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 12:41:06 by sharris           #+#    #+#             */
/*   Updated: 2018/10/18 12:41:08 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			is_hexchar(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')
	|| (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}

static int			get_hex_charv(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1000000);
}

long long			get_hex_value(char *str)
{
	long long	out;
	int			len;

	out = 0;
	len = 0;
	while (is_hexchar(str[len++ + 1]))
		;
	while (is_hexchar(*str))
	{
		out += get_hex_charv(*str) * ft_pow(16, --len);
		str++;
	}
	return (out);
}

long long			ft_hextoi(char *str)
{
	while (ft_iswhitespace(*str))
		str++;
	if (ft_strnstr(str, "0x", 2) || ft_strnstr(str, "0X", 2))
		str += 2;
	if (is_hexchar(*str))
		return (get_hex_value(str));
	return (0);
}
