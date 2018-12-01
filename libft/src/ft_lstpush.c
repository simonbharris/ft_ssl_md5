/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 23:36:15 by sharris           #+#    #+#             */
/*   Updated: 2018/07/28 23:36:15 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list *cur;

	if (*alst)
	{
		cur = *alst;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	else
		*alst = new;
}
