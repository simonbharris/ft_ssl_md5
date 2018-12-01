/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrffjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:51:51 by sharris           #+#    #+#             */
/*   Updated: 2018/09/27 17:51:54 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

wchar_t		*ft_wstrffjoin(wchar_t **dst, wchar_t **src)
{
	wchar_t *tmp;

	if (*dst == NULL)
		*dst = ft_wstrdup(L"");
	tmp = ft_wstrdup(*dst);
	ft_memdel((void **)&(*dst));
	*dst = ft_wstrjoin(tmp, *src);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&(*src));
	return (*dst);
}
