/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:52:45 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 20:52:46 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Obtains the parameter as an unsigned value, and returns it as octal.
*/

char	*pf_o(t_pfdrcv drcv, va_list ap)
{
	size_t i;

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
	return (ft_itoabase(i, "01234567"));
}
