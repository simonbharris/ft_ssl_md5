/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstolsts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 07:05:10 by sharris           #+#    #+#             */
/*   Updated: 2018/11/16 07:05:10 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_strstolsts(char **strings)
{
	t_list	*start;
	int		i;

	i = -1;
	start = NULL;
	while (strings[++i])
		ft_lstadd(&start, ft_lstnew(strings[i], ft_strlen(strings[i]) + 1));
	return (start);
}
