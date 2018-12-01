/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:23:28 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 19:23:31 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** ft_itoabase
** Converts the unsigend value into a string represenation.
** Returns a fresh, malloced string containing the results.
** Value prints using base as a key.
** Example, to print in hex (Base16) pass "0123456789abcdef" into base.
** Repeat characters in base causes undefined behavior.
*/

static int	get_allocsize(size_t nbr, int blen)
{
	int i;

	i = 1;
	if (nbr == 0)
		return (i);
	while (((nbr /= blen) > 0))
		i++;
	return (i);
}

char		*ft_itoabase(size_t nbr, char *base)
{
	char	*str;
	int		blen;
	int		len;

	blen = ft_strlen(base);
	if (blen < 2)
		return (NULL);
	len = get_allocsize(nbr, blen);
	str = ft_strnew((size_t)len);
	if (nbr == 0)
	{
		*str = '0';
		return (str);
	}
	while (nbr > 0)
	{
		str[--len] = *((nbr % ft_strlen(base) + base));
		nbr /= ft_strlen(base);
	}
	return (str);
}
