/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:37:04 by sharris           #+#    #+#             */
/*   Updated: 2018/07/12 21:37:04 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int is_neg;
	int res;

	res = 0;
	is_neg = 0;
	if (!*str)
		return (0);
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\v' || *str == '\r' || *str == '\f'))
		str++;
	if (*str == '-')
		is_neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_isdigit((int)*str))
		while (ft_isdigit((int)*str))
		{
			res *= 10;
			res += *str++ - '0';
		}
	if (is_neg)
		return (-res);
	return (res);
}
