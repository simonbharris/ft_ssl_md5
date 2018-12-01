/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:55:54 by sharris           #+#    #+#             */
/*   Updated: 2018/09/25 15:56:03 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Pads the given string address on the left or right side,
** Depends on the given flags.
*/

char	*pf_pad(t_pfdrcv drcv, char **astr)
{
	char *pad;

	if (drcv.oflags & PFO_S && drcv.oflags & PFO_L)
	{
		if (drcv.mfw > (int)ft_wstrlen((wchar_t *)*astr))
		{
			pad = (char *)gen_wpadding(drcv.mfw -
				ft_wstrlen((wchar_t *)*astr), L' ');
			*astr = (char *)ft_wstrffjoin((wchar_t **)&pad, (wchar_t **)astr);
		}
	}
	else if (drcv.mfw > (int)ft_strlen(*astr))
	{
		pad = gen_padding(drcv.mfw - ft_strlen(*astr) -
			((drcv.oflags & PFO_NULB) == PFO_NULB), ' ');
		*astr = ft_strffjoin(&pad, astr);
	}
	return (*astr);
}

char	*pf_lpad(t_pfdrcv drcv, char **astr)
{
	char *pad;

	if ((drcv.oflags & PFO_LPD) && (drcv.oflags & PFO_S)
	&& (drcv.oflags & PFO_L) && (drcv.mfw > (int)ft_wstrlen((wchar_t *)*astr)))
	{
		pad = (char *)gen_wpadding(drcv.mfw -
			ft_wstrlen((wchar_t *)*astr), L' ');
		*astr = (char *)ft_wstrffjoin((wchar_t **)astr, (wchar_t **)&pad);
	}
	else if ((drcv.oflags & PFO_LPD) && drcv.mfw > (int)ft_strlen(*astr))
	{
		if (drcv.oflags & (PFO_D | PFO_I) && drcv.oflags & PFO_SPC
		&& !(drcv.oflags & PFO_SIGN) && drcv.mfw > 0)
			drcv.mfw -= 1;
		pad = gen_padding(drcv.mfw - ft_strlen(*astr), ' ');
		*astr = ft_strffjoin(astr, &pad);
	}
	return (*astr);
}
