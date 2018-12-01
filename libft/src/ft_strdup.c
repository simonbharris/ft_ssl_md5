/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:13:25 by sharris           #+#    #+#             */
/*   Updated: 2018/07/12 16:13:25 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	if (NULL == (str = ft_strnew(ft_strlen(s1))))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	return (str);
}
