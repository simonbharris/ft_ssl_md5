/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 20:44:08 by sharris           #+#    #+#             */
/*   Updated: 2018/07/16 20:44:08 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Adds a new list to the front of alst
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *old;

	if (!*alst)
		old = NULL;
	else
		old = *alst;
	new->next = old;
	*alst = new;
}
