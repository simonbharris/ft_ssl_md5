/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:23:34 by sharris           #+#    #+#             */
/*   Updated: 2018/07/12 14:23:34 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Allocates a "Fresh" malloced string, null terminated
** New string contains the concat of s1 and s2
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		i;

	i = 0;
	if (!s1 || !s2 || NULL == (out = ft_strnew((ft_strlen(s1) +
		ft_strlen(s2)))))
		return (NULL);
	while (*s1)
		out[i++] = *s1++;
	while (*s2)
		out[i++] = *s2++;
	out[i] = '\0';
	return (out);
}
