/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdrcv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:00:45 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 16:00:46 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Dispatches for numeric types.
*/

char			*pf_dioux(t_pfdrcv drcv, va_list ap)
{
	if (drcv.oflags & (PFO_D | PFO_I))
		return (pf_di(drcv, ap));
	else if (drcv.oflags & PFO_O)
		return (pf_o(drcv, ap));
	else if (drcv.oflags & PFO_U)
		return (pf_u(drcv, ap));
	else if (drcv.oflags & PFO_X)
		return (pf_x(drcv, ap));
	else if (drcv.oflags & PFO_B)
		return (pf_b(drcv, ap));
	return (NULL);
}

/*
** Dispatches the given directive(drcv) into one of the possible datatypes.
** Passes the returned char* up
*/

char			*dispatcher(t_pfdrcv *drcv, va_list ap)
{
	if (drcv->oflags & PFO_DIOUXB)
		return (pf_dioux(*drcv, ap));
	else if (drcv->oflags & PFO_S)
		return (pf_s(*drcv, ap));
	else if (drcv->oflags & PFO_P)
		return (pf_p(*drcv, ap));
	else if (drcv->oflags & PFO_C)
		return (pf_c(drcv, ap));
	else if (drcv->oflags & PFO_ESC)
		return (ft_strdup("%"));
	return (NULL);
}

/*
** Modifies the string passed by address with the format specified with
** the directive(drcv)
*/

static void		applyfmt(t_pfdrcv drcv, char **astr)
{
	if (drcv.oflags & PFO_ALT || drcv.oflags & PFO_PREC || drcv.oflags & PFO_P)
		pf_prec(drcv, astr);
	else if (drcv.oflags & PFO_PAD0 && !(drcv.oflags & PFO_LPD))
		pf_zero(drcv, astr);
	if (drcv.oflags & PFO_SIGN)
		pf_sign(drcv, astr);
	if (drcv.oflags & PFO_LPD && drcv.mfw > (int)ft_strlen(*astr))
		pf_lpad(drcv, astr);
	else if (drcv.mfw > (int)ft_strlen(*astr))
		pf_pad(drcv, astr);
	if (drcv.oflags & PFO_SPC)
		pf_space(drcv, astr);
}

/*
** Prints the string to stdout. Checks some flags for special cases.
*/

static void		pf_putfmt(t_pfdrcv drcv, char *str)
{
	if ((drcv.oflags & PFO_S) && (drcv.oflags & PFO_L))
		ft_putwstr((wchar_t *)str);
	else if ((drcv.oflags & PFO_C))
		if (drcv.oflags & PFO_LPD)
		{
			if (drcv.oflags & PFO_NULB)
				write(1, "\0", 1);
			ft_putstr(str);
		}
		else
		{
			ft_putstr(str);
			if (drcv.oflags & PFO_NULB)
				write(1, "\0", 1);
		}
	else
		ft_putstr(str);
}

/*
** Handles getting the param from va_list,
** modifying the returned char *, prints it,
** then returns bytes printed.
*/

int				put_drcv(t_pfdrcv drcv, va_list ap)
{
	char	*str;
	int		len;

	if ((str = dispatcher(&drcv, ap)) == NULL)
		return (0);
	applyfmt(drcv, &str);
	pf_putfmt(drcv, str);
	len = ft_strlen(str);
	if (drcv.oflags & PFO_NULB)
		len++;
	ft_memdel((void **)&str);
	return (len);
}
