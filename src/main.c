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
 * Still need to be able to read from stdin
 *
 * Specifying hash type without any other input results in just a new line printing
 * 		the md5 binary switches to expect an input from the user.
 *      This ties in with the above objective for reading from stdin.
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


/*
** ssl_funct's function pointers are char *(*)(char *)
** Passed parameter is the message, return is the malloced digest.
*/

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
		ft_printf("ft_ssl: %s Cannot open, check name and permissions\n", file);
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

/*
** Should be run on the argv[] that contains the '-s' string.
** Detects if the string is provided in the same 'string' or as a separate parameter,
** IE: '-shello' vs '-s hello'
** argv_offset is the argv addressed pass at a specific point in the index, IE: &argv[3]
**      in such that argv_offset[0] will contain the '-s' option.
*/

void handle_string_option(char **argv_offset, const t_ssl_f *ssl_f, int *i)
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
        ft_printf("ft_ssl: option requires an argument -- s");
        ft_ssl_md5_usage();
        return ;
    }
    free(digest);
}

void print_hash(char **argv, const t_ssl_f *ssl_f)
{
	int i;
	char *digest;
	char *file_content;

	i = 0;
	if (argv[i] && argv[i][0] == '-' && argv[i][1])
		load_ftssl_opts(argv[i]);
	if (g_ft_ssl_flags & FTSSL_S)
    {
        while (argv[i] && ft_strncmp(argv[i], "-s", 2) == 0)
        {
            handle_string_option(&argv[i], ssl_f, &i);
        }
	}
	while (argv[i])
	{
        if ((file_content = get_file_contents(argv[i])) != NULL)
        {
            digest = ssl_f->funct(file_content);
            ft_memdel((void **) &(file_content));
            print_explicit_format(*ssl_f, digest, argv[i], 0);
        }
        ft_memdel((void **)&(digest));
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
			ft_printf("ft_ssl: Error: '%s' is an invalid command\n", argv[1]);
            ft_ssl_md5_usage();
		}
	}
	return(0);
}
