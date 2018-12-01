/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:13:34 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 11:13:35 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Wide string copy
** Returns a fresh malloc of the contents of null-terminated s1
*/

wchar_t	*ft_wstrdup(const wchar_t *s1)
{
	int		i;
	wchar_t	*str;

	i = -1;
	if (NULL == (str = ft_wstrnew(ft_wstrlen(s1))))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	return (str);
}
