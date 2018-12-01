/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:44:44 by sharris           #+#    #+#             */
/*   Updated: 2018/10/22 12:44:46 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Takes a double pointer
** Returns the number of pointers pointed to by arr
** The array must be NULL-terminated.
*/

int		ft_parrlen(void **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
