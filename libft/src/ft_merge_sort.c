/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 05:59:09 by sharris           #+#    #+#             */
/*   Updated: 2018/11/18 05:59:10 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define MRG_SRT_REV_FLAG ((rev_flag > 0) ? -1 : 1)

/*
** ft_merge_sort -- Uses the merge sort method to sort a linked list.
** Merge sort takes a link-list of values,
** and sorts them with passed function, cmp, which defines how they are sorted.
**
** cmp should return a non-zero if t1 and t2 are not equal.
** a return of 0 for cmp means t1 and t2 are equal (Similar to strcmp)
**
** if rev_flag == 1, the return will reverse the cmp results.
*/

static t_list	*merge_lists(t_list *t1, t_list *t2,
							int (cmp)(void *, void *), int rev_flag)
{
	t_list head;
	t_list *node;

	head.next = NULL;
	node = &head;
	while (t1 && t2)
	{
		if ((MRG_SRT_REV_FLAG * cmp(t1->content, t2->content)) > 0)
		{
			node->next = t2;
			t2 = t2->next;
		}
		else
		{
			node->next = t1;
			t1 = t1->next;
		}
		node = node->next;
	}
	node->next = t1 ? t1 : t2;
	return (head.next);
}

t_list			*ft_merge_sort(t_list *head,
								int cmp(void *, void *), int rev_flag)
{
	t_list *pre;
	t_list *slow;
	t_list *fast;

	pre = head;
	fast = head;
	slow = head;
	if (!head || !head->next)
		return (head);
	while (fast && fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = NULL;
	return (merge_lists(ft_merge_sort(head, cmp, rev_flag),
		ft_merge_sort(slow, cmp, rev_flag), cmp, rev_flag));
}
