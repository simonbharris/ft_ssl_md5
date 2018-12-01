/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:54:01 by sharris           #+#    #+#             */
/*   Updated: 2018/07/16 16:54:01 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *lnext;

	if (alst == NULL || *alst == NULL || !del)
		return ;
	lst = *alst;
	while (lst)
	{
		lnext = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lnext;
	}
	*alst = NULL;
}
