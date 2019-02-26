/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_explicit_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:33:49 by sharris           #+#    #+#             */
/*   Updated: 2019/02/21 22:33:55 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** The output format depends on what the original
** parameter was, this is tracked by is_string.
*/

static void	print_original(char *o, int is_string)
{
	if (is_string)
		ft_printf("\"%s\"", o);
	else
		ft_printf("%s", o);
}

/*
** Formats the output into an explicit output print
*/

void		print_explicit_format(
	t_ssl_f hashtype,
	char *out_digest,
	char *original,
	int is_string)
{
	if (g_ft_ssl_flags & FTSSL_Q)
		ft_printf(out_digest);
	else if (g_ft_ssl_flags & FTSSL_R)
	{
		ft_printf("%s ", out_digest);
		print_original(original, is_string);
	}
	else
	{
		ft_putupper(hashtype.name);
		ft_printf(" (");
		print_original(original, is_string);
		ft_printf(") = %s", out_digest);
	}
	ft_printf("\n");
}
