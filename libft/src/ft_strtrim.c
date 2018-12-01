/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 15:05:53 by sharris           #+#    #+#             */
/*   Updated: 2018/07/11 15:05:53 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		b;
	int		e;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	e = i;
	b = i--;
	while (s[++i])
		if (s[i] && !(s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			e = i;
	if (s[0] == '\0')
		str = ft_strnew(0);
	else
		str = ft_strnew(e - b + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (b <= e)
		str[i++] = s[b++];
	return (str);
}
