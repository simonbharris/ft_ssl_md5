/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:24:37 by sharris           #+#    #+#             */
/*   Updated: 2018/07/12 20:24:37 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char *hold;

	hold = NULL;
	while (*s)
	{
		if (*s == (char)c)
			hold = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (hold);
}
