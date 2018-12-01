/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 06:50:18 by sharris           #+#    #+#             */
/*   Updated: 2018/11/12 00:43:54 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <locale.h>
# include <stdarg.h>
# include <libft.h>

# define TRUE 1
# define FALSE 0
# define IS_SIGN(x) x == '+' || x == '-'

/*
** ft_printf types and modifiers
*/

# define PF_DFLAG "sSpdDioOuUxXcC"
# define IS_MOD(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')
# define IS_2CHARMOD(x) ((x)[1] == 'h' || (x)[1] == 'l')

/*
** Option Flag tabke for ft_printf
** 0000xx == options and precision flags
** 00xx00 == length modifier flags*
** xx0000 == type modifier flags*
**
** Exceptions:
** 000040 (PFO_ESC) Asked to print escape character.
** 000080 (PFO_ISNEG) Input signed numeric is negative.
** 004000 (PFO_NULB) Asked to print a null-byte character.
** 008000 (PFO_B) Is a type mod.
*/

# define PFO_ALT	0x000001
# define PFO_PAD0	0x000002
# define PFO_SPC	0x000004
# define PFO_LPD	0x000008

# define PFO_SIGN	0x000010
# define PFO_PREC	0x000020
# define PFO_ESC	0x000040
# define PFO_ISNEG	0x000080

# define PFO_2MOD	0x000100
# define PFO_H		0x000200
# define PFO_L		0x000400
# define PFO_J		0x000800
# define PFO_Z		0x001000
# define PFO_CAPS	0x002000
# define PFO_NULB	0x004000

# define PFO_B		0x008000

# define PFO_S		0x010000
# define PFO_P		0x020000
# define PFO_D		0x040000
# define PFO_I		0x080000
# define PFO_O		0x100000
# define PFO_U		0x200000
# define PFO_X		0x400000
# define PFO_C		0x800000

/*
** Compound flags
*/

# define PFO_HH		0x000300
# define PFO_LL		0x000500
# define PFO_DIOUXB	0x7c8000
# define PFO_SC		0x810000
# define PFO_DI		0x0c0000

/*
** s_pfdir (aka struct printf_directive)
** oflags == tracks various flags. Is a result of the comination of
**		the above defines.
** mfw == Value of minimum field width.
** pv == Value of precision.
*/

typedef struct	s_pfdrcv
{
	int		oflags;
	int		pv;
	int		mfw;
}				t_pfdrcv;

int				ft_printf(const char *format, ...);

/*
** Utilities
*/

t_pfdrcv		get_drcv(const char *format);
int				put_drcv(t_pfdrcv drcv, va_list ap);
void			skip_atoi(const char **str);
t_pfdrcv		initpfdir(void);
char			*gen_padding(int len, int c);
wchar_t			*gen_wpadding(int len, wchar_t c);
int				set_numeric_type(t_pfdrcv *drcv, const char **format);
void			set_lmod(t_pfdrcv *drcv, const char **format);
void			set_type(t_pfdrcv *drcv, const char **format);
void			set_opt(t_pfdrcv *drcv, const char c);
int				is_hexzero(char *str);

/*
** Functions to handle flags.
*/

char			*pf_di(t_pfdrcv drcv, va_list ap);
char			*pf_o(t_pfdrcv drcv, va_list ap);
char			*pf_u(t_pfdrcv drcv, va_list ap);
char			*pf_x(t_pfdrcv drcv, va_list ap);
char			*pf_s(t_pfdrcv drcv, va_list ap);
char			*pf_c(t_pfdrcv *drcv, va_list ap);
char			*pf_p(t_pfdrcv drcv, va_list ap);
char			*pf_prec(t_pfdrcv drcv, char **astr);
char			*pf_zero(t_pfdrcv drcv, char **astr);
char			*pf_pad(t_pfdrcv drcv, char **astr);
char			*pf_lpad(t_pfdrcv drcv, char **astr);
char			*pf_sign(t_pfdrcv drcv, char **astr);
char			*pf_space(t_pfdrcv drcv, char **astr);
char			*pf_b(t_pfdrcv drcv, va_list ap);

#endif
