/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_ftssl_opts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 20:54:10 by sharris           #+#    #+#             */
/*   Updated: 2019/02/28 20:54:11 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

int			get_ft_ssl_opt(char c)
{
	int i;

	i = 0;
	while (g_ssl_opts[i].c)
	{
		if (c == g_ssl_opts[i].c)
			return (g_ssl_opts[i].flag);
		i++;
	}
	return (0);
}

static void	print_invalid_ssl_flag(char c)
{
	ft_printf("ft_ssl: Error: Invalid flag: %c\n", c);
	ft_ssl_usage();
	exit(0);
}

void		load_ftssl_opts(char **argv, int *ai)
{
	int i;
	int j;
	int val;

	i = 0;
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		j = 0;
		while (argv[i][++j])
		{
			if ((val = get_ft_ssl_opt(argv[i][j])) > 0)
				g_ft_ssl_flags |= val;
			else
				print_invalid_ssl_flag(argv[i][j]);
			if (val == FTSSL_S)
			{
				*ai += i;
				return ;
			}
		}
		i++;
	}
	*ai += i;
}
