/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:17:33 by sharris           #+#    #+#             */
/*   Updated: 2018/09/22 12:17:49 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Obtains the parameter as a (int)char or wchar_t
*/

char	*pf_c(t_pfdrcv *drcv, va_list ap)
{
	char	*str;
	wchar_t	wc;

	if (drcv->oflags & PFO_L)
	{
		if (NULL == (str = (char *)ft_wstrnew(sizeof(wchar_t) * 2)))
			return (NULL);
		wc = va_arg(ap, wchar_t);
		ft_wstrcpy((wchar_t *)str, &wc);
		str[1] = L'\x0';
		if (str[0] == 0)
			drcv->oflags |= PFO_NULB;
		return ((char *)str);
	}
	else
	{
		if (NULL == (str = ft_strnew(1)))
			return (NULL);
		str[0] = va_arg(ap, int);
		if (str[0] == 0)
			drcv->oflags |= PFO_NULB;
		return (str);
	}
}
