/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:55:48 by sharris           #+#    #+#             */
/*   Updated: 2018/09/27 17:55:53 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

wchar_t	*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t	*out;
	int		i;

	i = 0;
	if (!s1 || !s2 || NULL == (out = ft_wstrnew((ft_wstrlen(s1) +
		ft_wstrlen(s2)))))
		return (NULL);
	while (*s1)
		out[i++] = *s1++;
	while (*s2)
		out[i++] = *s2++;
	out[i] = L'\0';
	return (out);
}
