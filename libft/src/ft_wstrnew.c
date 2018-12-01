/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:17:22 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 11:17:22 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** wide string new.
** returns a fresh malloc of a null-terminated wchar_t array.
*/

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t *str;

	if (NULL == (str = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	ft_memset(str, L'\x0', sizeof(wchar_t) * (size + 1));
	return (str);
}
