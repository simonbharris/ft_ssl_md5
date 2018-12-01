/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:02:38 by sharris           #+#    #+#             */
/*   Updated: 2018/07/12 21:02:38 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** compares lexicographically s1 and s2.
** returns the diff of the last compared characters, thus..
** 0 == match, positive = s1 is "higher", negative s2 is "higher"
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *u1;
	unsigned char *u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (*u1 && *u2)
	{
		if (*u1 != *u2)
			return ((int)(*u1 - *u2));
		u1++;
		u2++;
	}
	return ((int)(*u1 - *u2));
}
