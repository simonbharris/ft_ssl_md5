/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:44:16 by sharris           #+#    #+#             */
/*   Updated: 2018/10/19 14:44:18 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *str, int n)
{
	char	*out;
	int		i;

	i = 0;
	if (NULL == (out = ft_strnew(n)))
		return (NULL);
	while (i < n)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
