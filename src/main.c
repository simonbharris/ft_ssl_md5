/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:30:50 by sharris           #+#    #+#             */
/*   Updated: 2018/12/03 11:05:51 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/ft_ssl_md5.h"
#include "../libft/includes/ft_printf.h"
#include <stdio.h>

char *debugsha256out(char *msg);
void ft_ssl_md5_usage(void);

/*
 * known bugs:
 * -shello should treat this as valid string representing "hello"
 *		This is most notable in the first set of options,
 *		IE: ... md5 -sqr does not treat this as quiet mode nore reverse. but instead a string representing "qr"
 *
 * Reading files gives unexpected results. I may be missing the newline character since GNL drops this.
 *
 * Reading from a file prints the format ("filename") rather than the expected (filename)
 *
 * Still need to be able to read from stdin
 *
 * Specifying hash type without any other input results in just a new line printing
 * 		the md5 binary switches to expect an input from the user.
 *
 *
 */

/*
** Keep 's' flag on the last position, since this is a special case for options.
*/

static const t_ssl_opts ssl_opts[] =
{
	{ 'p', FTSSL_P }, // Echo stdin
	{ 'q', FTSSL_Q }, // Quiet
	{ 'r', FTSSL_R }, // Reverse output format
	{ 's', FTSSL_S }, // Designates the following is a string
	{ '\0', 0 }
};

static const t_ssl_f ssl_functs[] =
{
	{ "md5", &ft_md5 },
	{ "sha256", &debugsha256out },
	{ NULL, NULL }
};

void ft_ssl_md5_usage(void)
{
	ft_printf("usage: ft_ssl_md5 command [command opts] [command args]\n");
}

void ft_ssl_help(void)
{
    int i;

    i = 0;
    ft_printf("usage: ft_ssl_md5 command [command opts] [command args]\n");
    ft_printf("commands: [md5 | sha256]\n");
	ft_printf("command opts: [-");
    while (ssl_opts[i].c && ssl_opts[i].c != 's')
        ft_printf("%c", ssl_opts[i++].c);
    ft_printf("][-s string]\n");

	exit(0);
}

/*
 * Remove this eventually
 */
char *debugsha256out(char *msg)
{
    msg += 0;
	ft_printf("SHA256 (\"Example\") = 0123456789abcdef0123456789abcdef\n");
    return(NULL);
}


/*
** Returns the binary flag value of what is represented bt the char c. 0 if no match
*/

int get_flag_val(char c)
{
	int i;

	i = 0;
	while (ssl_opts[i].c)
	{
		if (ssl_opts[i].c == c)
			return (ssl_opts[i].flag);
		i++;
	}
	return (0);
}

/*
** Outputs invalid flags
*/
static char ftssl_err_opt(char c)
{
	ft_printf("ft_ssl_md5: illegal option -- %c\n", c);
	exit(0);
}

int load_ftssl_opts(char *opts)
{
	int i;
	int val;

	i = 0;
	if (opts[i] == '-' && opts[i + 1])
	{
		i++;
		while (opts[i])
		{
			if (!(val = get_flag_val(opts[i])))
				ftssl_err_opt(opts[i]);
			g_ft_ssl_flags |= val;
			i++;
		}
		return (1);
	}
	return (0);
}

/*
** Returns a char * that contains all the contents of a file.
*/

char *get_file_contents(char *file)
{
	int fd;
	char *contents;
	char *line;

	contents = NULL;
	if ((fd = open(file, O_RDONLY)) > -1)
	{
		while (get_next_line(fd, &line) > 0)
			contents = ft_strffjoin(&contents, &line);
	}
	else
		ft_printf("Error, Unable to read file, %s, check name and permissions\n", file);
	return (contents);
}

/*
** The output format depends on what the input was.
*/

void print_original(char *o, int is_string)
{
	if (is_string)
	{
		ft_printf("\"%s\"", o);
	}
	else
		ft_printf("%s", o);
}

/*
** Formats the output into an explicit output print
*/

void print_explicit_format(t_ssl_f hashtype, char* out_digest, char *original , int is_string)
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

void print_hash(char **argv, const t_ssl_f *ssl_f)
{
	int i;
	char *digest;
	char *file_content;

	i = 0;
	if (argv[i] && argv[i][0] == '-' && argv[i][1])
		load_ftssl_opts(argv[i++]);
	if (g_ft_ssl_flags & FTSSL_S)
	{
        digest = ssl_f->funct(argv[i]);
        print_explicit_format(*ssl_f, digest, argv[i++], 1);
	}
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-s") && argv[i + 1])
		{
			digest = ssl_f->funct(argv[++i]);
			print_explicit_format(*ssl_f, digest, argv[i], 1);
		}
		else
		{
			digest = ssl_f->funct(file_content = get_file_contents(argv[i]));
			ft_memdel((void **)&(file_content));
			print_explicit_format(*ssl_f, digest, argv[i], 1);
		}
		free(digest);
		i++;
	}
}

int main(int argc, char **argv)
{
	char *str;
	const t_ssl_f *sfunct;

	g_ft_ssl_flags = 0;
	if (argc < 2)
		ft_ssl_md5_usage();
    else if (argc >= 2 && ft_strequ("help", argv[1]))
        ft_ssl_help();
	else
	{
		int i = 0;
		while (ssl_functs[i].name)
		{
			if (ft_strequ(ssl_functs[i].name, argv[1]))
			{
				sfunct = &ssl_functs[i];
				print_hash(&argv[2], sfunct);
				break ;
			}
			i++;
		}
		if (!ssl_functs[i].name)
		{
			ft_printf("ft_ssl_md5: Error: '%s' is an invalid command\n", argv[1]);
            ft_ssl_md5_usage();
		}
	}
	return(0);
}
