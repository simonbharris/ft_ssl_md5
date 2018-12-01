/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 23:35:35 by sharris           #+#    #+#             */
/*   Updated: 2018/09/25 23:35:36 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** '+' flag, ensures that the printed signed numeric is printing with a '+'
** if it is positive.
*/

char	*pf_sign(t_pfdrcv drcv, char **astr)
{
	if ((drcv.oflags & PFO_SIGN) && (drcv.oflags & PFO_DI)
	&& ft_atoi(*astr) >= 0)
	{
		if (drcv.mfw == (int)ft_strlen(*astr) && **astr == '0')
			**astr = '+';
		else
			*astr = ft_strcfjoin("+", astr);
	}
	return (*astr);
}
