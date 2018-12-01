/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 20:58:52 by sharris           #+#    #+#             */
/*   Updated: 2018/07/09 20:58:52 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	get_alloc_size(int nbr)
{
	int		digitpos;
	int		i;

	digitpos = 1000000000;
	i = 10;
	while (digitpos != 0 && nbr / digitpos == 0)
	{
		digitpos /= 10;
		i--;
	}
	if (nbr <= 0)
		return (i + 2);
	return (i + 1);
}

static int	check_neg_make_abs(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	else
		return (0);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (NULL == (str = ft_memalloc(get_alloc_size(n))))
		return (NULL);
	if (n == -2147483648)
		ft_strcpy(&(*str), "-2147483648");
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
