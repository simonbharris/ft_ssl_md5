/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:00:30 by sharris           #+#    #+#             */
/*   Updated: 2018/07/13 15:00:30 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	int		i;

	i = 0;
	if (NULL == (lst = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	lst->next = NULL;
	if (content == NULL)
		lst->content_size = 0;
	else
		lst->content_size = content_size;
	if (lst->content_size == 0)
		lst->content = NULL;
	else
	{
		lst->content = ft_memalloc(content_size);
		lst->content = ft_memcpy(lst->content, content, lst->content_size);
	}
	return (lst);
}
