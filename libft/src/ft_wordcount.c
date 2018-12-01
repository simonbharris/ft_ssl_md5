/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:01:38 by sharris           #+#    #+#             */
/*   Updated: 2018/07/17 14:01:38 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_wordcount(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		while (ft_iswhitespace(*s))
			s++;
		if (*s)
			i++;
		while (*s && !ft_iswhitespace(*s))
			s++;
	}
	return (i);
}
