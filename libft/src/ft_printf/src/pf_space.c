/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:25:20 by sharris           #+#    #+#             */
/*   Updated: 2018/09/25 16:25:28 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Ensures that there is left padding enough reserved for a '-' sign if
** the value is negative.
*/

char	*pf_space(t_pfdrcv drcv, char **astr)
{
	if ((drcv.oflags & PFO_SPC) && !(drcv.oflags & PFO_SIGN)
	&& (drcv.oflags & PFO_DI)
	&& (**astr && **astr != ' ' && **astr != '-'))
		*astr = ft_strcfjoin(" ", astr);
	return (*astr);
}
