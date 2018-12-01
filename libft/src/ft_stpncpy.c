/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:59:25 by sharris           #+#    #+#             */
/*   Updated: 2018/07/29 17:59:25 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_stpncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = -1;
	while (src[++i] && i < (int)len)
		dst[i] = src[i];
	while (i < (int)len)
	{
		dst[i] = '\0';
		i++;
	}
	return (&dst[i]);
}
