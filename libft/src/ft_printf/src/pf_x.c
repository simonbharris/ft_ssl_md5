/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 06:33:50 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 06:34:19 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Obtains the given parameter as an unsigned value, then outputs it as hex.
*/

char	*pf_x(t_pfdrcv drcv, va_list ap)
{
	size_t	i;

	if ((drcv.oflags & PFO_LL) == PFO_LL)
		i = va_arg(ap, unsigned long long);
	else if (drcv.oflags & PFO_L)
		i = va_arg(ap, unsigned long);
	else if ((drcv.oflags & PFO_HH) == PFO_HH)
		i = (unsigned char)va_arg(ap, unsigned int);
	else if (drcv.oflags & PFO_H)
		i = (unsigned short)va_arg(ap, unsigned int);
	else if (drcv.oflags & PFO_J)
		i = va_arg(ap, uintmax_t);
	else if (drcv.oflags & PFO_Z)
		i = va_arg(ap, size_t);
	else
		i = va_arg(ap, unsigned int);
	if (drcv.oflags & PFO_CAPS)
		return (ft_itoabase(i, "0123456789ABCDEF"));
	return (ft_itoabase(i, "0123456789abcdef"));
}
