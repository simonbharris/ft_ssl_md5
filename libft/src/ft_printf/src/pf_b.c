/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:02:50 by sharris           #+#    #+#             */
/*   Updated: 2018/09/26 14:03:13 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** pf_b
** Obtains the parameter in binary
*/

char	*pf_b(t_pfdrcv drcv, va_list ap)
{
	size_t i;

	if ((drcv.oflags & PFO_HH) == PFO_HH)
		i = va_arg(ap, unsigned int);
	else if (drcv.oflags & PFO_H)
		i = va_arg(ap, unsigned int);
	else if ((drcv.oflags & PFO_LL) == PFO_LL)
		i = va_arg(ap, unsigned long long);
	else if (drcv.oflags & PFO_L)
		i = va_arg(ap, unsigned long);
	else if (drcv.oflags & PFO_J)
		i = va_arg(ap, uintmax_t);
	else if (drcv.oflags & PFO_Z)
		i = va_arg(ap, size_t);
	else
		i = va_arg(ap, unsigned int);
	if (drcv.oflags & PFO_CAPS)
		return (ft_itoabase(i, "01"));
	return (ft_itoabase(i, "01"));
}
