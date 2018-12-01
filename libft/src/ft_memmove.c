/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:18:49 by sharris           #+#    #+#             */
/*   Updated: 2018/07/12 15:18:49 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	i = -1;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s > d)
		while (++i < (int)len)
			d[i] = s[i];
	else
		while (len-- > 0)
			d[len] = s[len];
	return (d);
}
