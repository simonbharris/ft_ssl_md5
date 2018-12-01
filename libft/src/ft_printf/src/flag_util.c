/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 01:23:19 by sharris           #+#    #+#             */
/*   Updated: 2018/10/01 01:23:21 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Details for the following 3 funcitons:
** set_opt = set options
** set_mfw_prec = sets the precision and mfw flags and also obtains
**		the minium field width and precision values.
** set_lmod = get length modifier
** set_type
** all 3 functions add flags to drcv.oflags depending on what they find.
*/

void		set_lmod(t_pfdrcv *drcv, const char **format)
{
	if (IS_MOD(**format))
	{
		if ((ft_strnequ(*format, "hh", 2) && (drcv->oflags |= PFO_HH))
		|| (ft_strnequ(*format, "ll", 2) && (drcv->oflags |= PFO_LL)))
			*format += 1;
		else if (**format == 'h')
			drcv->oflags |= PFO_H;
		else if (**format == 'l')
			drcv->oflags |= PFO_L;
		else if (**format == 'j')
			drcv->oflags |= PFO_J;
		else if (**format == 'z')
			drcv->oflags |= PFO_Z;
	}
}

void		set_type(t_pfdrcv *drcv, const char **format)
{
	if (ft_strchr("DOUSC", (int)**format))
		drcv->oflags |= PFO_L;
	if (set_numeric_type(drcv, format))
		return ;
	else if (ft_tolower((int)**format) == 's')
		drcv->oflags |= PFO_S;
	else if (ft_tolower((int)**format) == 'c')
		drcv->oflags |= PFO_C;
	else if (**format == '%')
		drcv->oflags |= PFO_ESC;
	else if (ft_tolower((int)**format) == 'x')
	{
		if (**format == 'X')
			drcv->oflags |= PFO_CAPS;
		drcv->oflags |= PFO_X;
	}
}

void		set_opt(t_pfdrcv *drcv, const char c)
{
	if (!(drcv->oflags & PFO_ALT) && (c == '#'))
		drcv->oflags |= PFO_ALT;
	if (!(drcv->oflags & PFO_PAD0) && (c == '0'))
		drcv->oflags |= PFO_PAD0;
	if (!(drcv->oflags & PFO_SPC) && (c == ' '))
		drcv->oflags |= PFO_SPC;
	if (!(drcv->oflags & PFO_LPD) && (c == '-'))
		drcv->oflags |= PFO_LPD;
	if (!(drcv->oflags & PFO_SIGN) && (c == '+'))
		drcv->oflags |= PFO_SIGN;
}

/*
** set_numeric_type
** Sets one of the numeric datatyles for drcv if the format specifies as such
*/

int			set_numeric_type(t_pfdrcv *drcv, const char **format)
{
	if (ft_tolower((int)**format) == 'd')
		drcv->oflags |= PFO_D;
	else if (ft_tolower((int)**format) == 'o')
		drcv->oflags |= PFO_O;
	else if (ft_tolower((int)**format) == 'u')
		drcv->oflags |= PFO_U;
	else if (ft_tolower((int)**format) == 'p')
		drcv->oflags |= PFO_P;
	else if (ft_tolower((int)**format) == 'i')
		drcv->oflags |= PFO_I;
	else if (**format == 'b')
		drcv->oflags |= PFO_B;
	else
		return (0);
	return (1);
}
