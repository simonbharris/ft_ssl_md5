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

#define MD5_SSL_BUFFSIZE 256

/*
 * known bugs:
 * -shello should treat this as valid string representing "hello"
 *		This is most notable in the first set of options,
 *		IE: ... md5 -sqr does not treat this as quiet nor reverse mode. but instead a string representing "qr"
 *
 * Reading files gives unexpected results. I may be missing the newline character since GNL drops this.
 *      UPDATE: Now gives the proper return, but debugging shows like it's iterating through the read way too many times. Check for problems and optimize.
 *      UPDATE: (Works in debug mode, not otherwise -- GRRRR)
 *      UPDATE: Nevermind, forgot to recompile dependency bugfix, forgot debugger compiles differently. ^^;
 *
 * Still need to be able to read from stdin
 *
 * Specifying hash type without any other input results in just a new line printing
 * 		the md5 binary switches to expect an input from the user.
 *      This ties in with the above objective for reading from stdin.
 *
 * Specifying absolute address for file causes a seg fault.
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
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
}

void ft_ssl_help(void)
{
    int i;

    i = 0;
    ft_ssl_md5_usage();
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
            if (opts[i] == 's')
                break ;
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
	char buffer[MD5_SSL_BUFFSIZE];
    char *tmp;
    int ret;

	contents = NULL;
	if ((fd = open(file, O_RDONLY)) > -1)
	{
		while ((ret = read(fd, buffer, MD5_SSL_BUFFSIZE)) > 0)
        {
            buffer[ret] = 0;
            tmp = contents;
            contents = ft_strjoin(contents, buffer);
            free(tmp);
        }
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

// TODO: HAve this function handle pulling the proper string for the -s coption, in addition to throwing out an error if nothing is supplied.
char *get_string_digest(char **argv_offset, t_ssl_f *ssl_f)
{
    int i;
    char *digest;
    char *tmp;

    tmp = ft_strchr(argv_offset[i], 's') + 1;
    if (*tmp)
        digest = ssl_f->funct(tmp);
    else if (argv_offset[++i] && argv_offset[i][0])
        digest = ssl_f->funct(argv_offset[i]);
    else
    {
        ft_printf("ft_ssl: option requires an argument -- s");
        ft_ssl_md5_usage();
    }
    return (digest);
}

void print_hash(char **argv, const t_ssl_f *ssl_f)
{
	int i;
	char *digest;
	char *file_content;
    char *tmp;

	i = 0;
	if (argv[i] && argv[i][0] == '-' && argv[i][1])
		load_ftssl_opts(argv[i]);
	if (g_ft_ssl_flags & FTSSL_S)
	{
        digest = ssl_f->funct(argv[++i]);
        print_explicit_format(*ssl_f, digest, argv[i], 1);
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
			print_explicit_format(*ssl_f, digest, argv[i], 0);
		}
		free(digest);
		i++;
	}
}

int main(int argc, char **argv)
{
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
