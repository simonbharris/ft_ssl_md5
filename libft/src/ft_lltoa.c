/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:58:52 by sharris           #+#    #+#             */
/*   Updated: 2018/09/27 17:57:40 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			get_alloc_size(long long nbr)
{
	int		i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr)
	{
		i++;
		nbr /= 10;
	}
	return (i + 1);
}

static long long	check_neg_make_abs(long long *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	else
		return (0);
}

char				*ft_lltoa(long long n)
{
	char			*str;
	long long		i;

	i = 0;
	if (NULL == (str = ft_strnew(get_alloc_size(n))))
		return (NULL);
	if ((unsigned long long)n == -9223372036854775808ULL)
		ft_strcpy(&(*str), "-9223372036854775808");
	else
	{
		i = get_alloc_size(n) - 1;
		if (n == 0)
			str[0] = '0';
		else
		{
			if (check_neg_make_abs(&n))
				str[0] = '-';
			while (n > 0)
			{
				str[--i] = ((n % 10) + '0');
				n /= 10;
			}
		}
	}
	return (str);
}
