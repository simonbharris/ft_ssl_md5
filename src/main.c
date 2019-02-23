/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:33:59 by sharris           #+#    #+#             */
/*   Updated: 2019/02/21 20:34:02 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <ft_ssl.h>

void	ft_ssl_usage(void)
{
	int i;

	i = 0;
	ft_printf("usage: ft_ssl command [-");
	while (ssl_opts[i].c && ssl_opts[i].c != 's')
		ft_printf("%c", ssl_opts[i++].c);
	ft_printf("] [-s string] [files ...]\n");
}

void	ft_ssl_help(void)
{
	int i;

	i = 0;
	ft_ssl_usage();
	ft_printf("commands: ");
	while (ssl_functs[i].name)
		ft_printf("%s ", ssl_functs[i++].name);
	ft_printf("\n");
	exit(0);
}

/*
** Should be run on the argv[] that contains the '-s' string.
** Detects if the string is provided in the same 'string'
** or as a separate parameter,
** IE: '-shello' vs '-s hello'
**
** argv_offset is the argv addressed pass at
** a specific point in the index, IE: &argv[3]
** in such that argv_offset[0] will contain the '-s' option.
*/

void	handle_string_option(char **argv_offset, const t_ssl_f *ssl_f, int *i)
{
	char *digest;
	char *tmp;

	tmp = ft_strchr(argv_offset[0], 's') + 1;
	if (*tmp)
	{
		digest = ssl_f->funct(tmp);
		print_explicit_format(*ssl_f, digest, tmp, 1);
		*i += 1;
	}
	else if (argv_offset[1])
	{
		digest = ssl_f->funct(argv_offset[1]);
		print_explicit_format(*ssl_f, digest, argv_offset[1], 1);
		*i += 2;
	}
	else
	{
		ft_printf("ft_ssl: option requires an argument -- s\n");
		ft_ssl_usage();
		exit(0);
	}
	free(digest);
}

void	print_hash(char **argv, const t_ssl_f *ssl_f)
{
	int		i;
	char	*digest;
	char	*file_content;

	i = 0;
	load_ftssl_opts(argv, &i);
	if (g_ft_ssl_flags & FTSSL_P || (argv[i] == NULL
	|| (argv[i][0] == '-' && argv[i + 1] == NULL)))
		handle_stdin(ssl_f);
	if (g_ft_ssl_flags & FTSSL_S)
		while (argv[i] && argv[i][0] == '-' && ft_strchr(argv[i], 's'))
			handle_string_option(&argv[i], ssl_f, &i);
	else if (g_ft_ssl_flags)
		i++;
	while (argv[i])
	{
		if ((file_content = get_file_contents(argv[i])) != NULL)
		{
			digest = ssl_f->funct(file_content);
			ft_memdel((void **)&(file_content));
			print_explicit_format(*ssl_f, digest, argv[i], 0);
			ft_memdel((void **)&(digest));
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	const t_ssl_f	*sfunct;
	int				i;

	g_ft_ssl_flags = 0;
	if (argc < 2)
		ft_ssl_usage();
	else if (argc >= 2 && ft_strequ("help", argv[1]))
		ft_ssl_help();
	else
	{
		i = -1;
		while (ssl_functs[++i].name)
			if (ft_strequ(ssl_functs[i].name, argv[1]))
			{
				sfunct = &ssl_functs[i];
				print_hash(&argv[2], sfunct);
				break ;
			}
		if (!ssl_functs[i].name)
		{
			ft_printf("ft_ssl: Error: '%s' is an invalid c ommand\n", argv[1]);
			ft_ssl_usage();
		}
	}
	return (0);
}
