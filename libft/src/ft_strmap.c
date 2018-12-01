/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:38:47 by sharris           #+#    #+#             */
/*   Updated: 2018/07/11 13:38:47 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*out;

	i = 0;
	size = 0;
	out = NULL;
	if (s)
	{
		while (s[size])
			size++;
		if (NULL == (out = ft_strnew(size)))
			return (NULL);
		while (i < size)
		{
			out[i] = f(s[i]);
			i++;
		}
	}
	return (out);
}
