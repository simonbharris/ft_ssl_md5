/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:57:14 by sharris           #+#    #+#             */
/*   Updated: 2018/09/20 15:57:15 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	putfmt(const char **afmt, va_list ap, int *numwrite)
{
	t_pfdrcv drcv;

	drcv = get_drcv(*afmt);
	*afmt += 1;
	while (!ft_strchr("sSpdDioOuUxXcCb%%", **afmt))
		*afmt += 1;
	if (**afmt)
		*afmt += 1;
	*numwrite += put_drcv(drcv, ap);
	return (*numwrite);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		numwrite;

	numwrite = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (putfmt(&format, ap, &numwrite))
				continue ;
		}
		else
		{
			ft_putchar(*format);
			numwrite++;
			format++;
		}
	}
	return (numwrite);
}
