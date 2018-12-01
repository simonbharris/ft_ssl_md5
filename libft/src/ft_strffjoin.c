/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strffjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 07:56:45 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 07:56:53 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** String Free - Free join
** Takes the address of two mallocced strings,
** returns and assigns the resulting join address to dst
** Frees up the old values to prevent leaks.
*/

char		*ft_strffjoin(char **dst, char **src)
{
	char *tmp;

	if (*dst == NULL)
		*dst = ft_strdup("");
	tmp = ft_strdup(*dst);
	ft_memdel((void **)&(*dst));
	*dst = ft_strjoin(tmp, *src);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&(*src));
	return (*dst);
}
