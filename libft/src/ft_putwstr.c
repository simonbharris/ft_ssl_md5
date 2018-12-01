/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:53:33 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 10:55:23 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Put wide string
** Writes to stdout an array of wchar_t
*/

void	ft_putwstr(wchar_t *wstr)
{
	int i;

	i = 0;
	while (*wstr)
	{
		write(1, wstr++, 1);
	}
}
