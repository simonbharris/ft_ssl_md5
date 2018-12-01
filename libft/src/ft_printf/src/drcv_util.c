/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drcv_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 06:37:02 by sharris           #+#    #+#             */
/*   Updated: 2018/09/17 06:37:14 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** initpfdir -- initialize a pfdir struct type.
** Initializes a pfdir struct, setting all values to defaults.
*/

t_pfdrcv	initpfdir(void)
{
	t_pfdrcv drcv;

	drcv.oflags = 0;
	drcv.mfw = 0;
	drcv.pv = 0;
	return (drcv);
}

/*
** skip_atoi
** leaps any digits in the string. Moves back 1 space so the guaranteed string
** increments in get_drcv don't seg fault--In case the skip places us
** on a null-byte.
*/

void		skip_atoi(const char **str)
{
	if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
			*str += 1;
		*str -= 1;
	}
}

/*
** gen_padding
** Generates a malloced string of len length
** String contents are filled with c characters.
** null-terminated.
*/

char		*gen_padding(int len, int c)
{
	char *out;

	out = ft_strnew(len);
	while (len-- > 0)
		out[len] = c;
	return (out);
}

/*
** Same as above, but for wide strings.
*/

wchar_t		*gen_wpadding(int len, wchar_t c)
{
	wchar_t *out;

	out = ft_wstrnew(len);
	while (len-- > 0)
		out[len] = c;
	return (out);
}

/*
** is_hexzero
** Since my atoi doesn't work with hex, this just sees if the
** string only contains zeros, if it does, the represented value is zero.
*/

int			is_hexzero(char *str)
{
	while (*str)
		if (*str++ != '0')
			return (0);
	return (1);
}
