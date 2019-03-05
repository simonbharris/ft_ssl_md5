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

#include <ft_ssl.h>

/*
** Prints the string associated with the -s option.
*/

void	print_stropt(char *str, t_msg *msg, const t_ssl_f *ssl_f)
{
	char *digest;

	msg->contents = (unsigned char *)ft_strdup(str);
	msg->len = ft_strlen(str);
	digest = ssl_f->funct(msg);
	print_explicit_format(*ssl_f, digest, str, 1);
	free(digest);
}

/*
** This handles the -s option.
** Works for both options where the string is passed as the same "word"
** `-shello` is equal to `-s "hello"`
*/

void	handle_string_option(char **argv_offset, const t_ssl_f *ssl_f, int *i)
{
	char	*tmp;
	t_msg	*msg;

	msg = init_msg();
	tmp = ft_strchr(argv_offset[0], 's') + 1;
	if (*tmp)
	{
		print_stropt(tmp, msg, ssl_f);
		*i += 1;
	}
	else if (argv_offset[1])
	{
		print_stropt(argv_offset[1], msg, ssl_f);
		*i += 2;
	}
	else
	{
		ft_printf("ft_ssl: option requires an argument -- s\n");
		ft_ssl_usage();
		exit(0);
	}
	del_msg(&msg);
}

/*
** Captured the options to be set for digest function,
** then loops all messages through digest.
*/

void	print_hash(char **argv, const t_ssl_f *ssl_f)
{
	int		i;
	char	*digest;
	t_msg	*message;

	i = 0;
	load_ftssl_opts(argv, &i);
	if ((g_ft_ssl_flags & FTSSL_P) || !((g_ft_ssl_flags & FTSSL_S) || argv[i]))
		handle_stdin(ssl_f);
	if (g_ft_ssl_flags & FTSSL_S)
		while (argv[i] && argv[i][0] == '-' && ft_strchr(argv[i], 's'))
			handle_string_option(&argv[i], ssl_f, &i);
	while (argv[i])
	{
		if ((message = get_file_contents(argv[i])) != NULL)
		{
			digest = ssl_f->funct(message);
			del_msg(&message);
			print_explicit_format(*ssl_f, digest, argv[i], 0);
			ft_memdel((void **)&(digest));
		}
		i++;
	}
}

/*
** Main handles usages, determined which function to run,
** and some error handling for lack of arguments.
*/

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
		while (g_ssl_functs[++i].name)
			if (ft_strequ(g_ssl_functs[i].name, argv[1]))
			{
				sfunct = &g_ssl_functs[i];
				print_hash(&argv[2], sfunct);
				break ;
			}
		if (!g_ssl_functs[i].name)
		{
			ft_printf("ft_ssl: Error: '%s' is an invalid command\n", argv[1]);
			ft_ssl_help();
		}
	}
	return (0);
}
