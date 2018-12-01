/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:15:51 by sharris           #+#    #+#             */
/*   Updated: 2018/07/17 14:15:51 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void **ptr, size_t old_size, size_t new_size)
{
	void *new;

	if (new_size == 0 || ptr == NULL || *ptr == NULL)
		return (NULL);
	new = ft_memalloc(new_size);
	new = ft_memcpy(new, *ptr, (old_size < new_size ? old_size : new_size));
	ft_memdel(*ptr);
	*ptr = new;
	return (new);
}
