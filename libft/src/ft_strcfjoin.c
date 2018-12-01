/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcfjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 07:56:45 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 07:56:53 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** String Constant - Free join
** Prepends the constant dst to the beginning of the address fo the malloced src
** frees char address pointed to by src;
*/

char		*ft_strcfjoin(const char *dst, char **src)
{
	char *ret;
	char *tmp;

	if (dst == NULL)
		tmp = ft_strdup("");
	else
		tmp = ft_strdup(dst);
	ret = ft_strjoin(tmp, *src);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&(*src));
	return (ret);
}
