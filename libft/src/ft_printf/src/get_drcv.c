/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 06:37:02 by sharris           #+#    #+#             */
/*   Updated: 2018/09/17 06:37:14 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Sets the mfw and pv values and flags when applicable.
*/

static void		set_mfw_prec(t_pfdrcv *drcv, const char **format)
{
	if (**format == '.' || ft_isdigit(**format))
	{
		if (**format == '.')
		{
			drcv->oflags |= PFO_PREC;
			if (ft_isdigit((*format)[1]))
				drcv->pv = ft_atoi((*format += 1));
		}
		else
			drcv->mfw = ft_atoi(*format);
		if (**format == '-' || ft_isdigit(**format))
			skip_atoi(format);
	}
}

/*
** get_drcv -- Get the directive.
** This functions parses the directive char '%'
** until a datatype character: sSpdDioOuUxXcC
** Stores the directive flags and values into a pfdir struct.
** Also advances the pointer to the format string the next
** non-option byte.
*/

t_pfdrcv		get_drcv(const char *format)
{
	t_pfdrcv drcv;

	drcv = initpfdir();
	format++;
	while (*format && !ft_strchr("sSpdDioOuUxXcCb%%", (int)*format))
	{
		set_opt(&drcv, *format);
		set_mfw_prec(&drcv, &format);
		set_lmod(&drcv, &format);
		format += 1;
	}
	set_type(&drcv, &format);
	format += 1;
	return (drcv);
}
