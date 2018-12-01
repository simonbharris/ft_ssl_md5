/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 21:28:00 by sharris           #+#    #+#             */
/*   Updated: 2018/07/16 21:28:00 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *curr;

	if (!lst)
		return (NULL);
	start = f(lst);
	curr = start;
	while (lst->next)
	{
		lst = lst->next;
		if (NULL == (curr->next = f(lst)))
		{
			free(curr->next);
			return (NULL);
		}
		curr = curr->next;
	}
	return (start);
}
