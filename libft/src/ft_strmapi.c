/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 13:53:53 by sharris           #+#    #+#             */
/*   Updated: 2018/07/11 13:53:53 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*out;

	i = 0;
	size = 0;
	if (!s)
		return (NULL);
	while (s[size])
		size++;
	if (NULL == (out = ft_strnew(size)))
		return (NULL);
	while (i < size)
	{
		out[i] = f(i, s[i]);
		i++;
	}
	return (out);
}
