/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:30:50 by sharris           #+#    #+#             */
/*   Updated: 2018/12/01 01:24:53 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ft_printf.h>

void debugsha256out(void);
void debugmd5out(void);
void ft_ssl_help(void);

static const char *str_commands[] = { "md5", "sha256", "help" };
static void (*command_funcs[])(void) = {&debugmd5out, &debugsha256out, &ft_ssl_help};

int get_funct_index(char *arg)
{
	int i = 0;
	while (str_commands[i])
		if (ft_strequ(str_commands[i], arg))
			return(i);
		else
			i++;
	return (-1);
}

void ft_ssl_md5_usage(void)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
}

void ft_ssl_help(void)
{
	ft_ssl_md5_usage();
	ft_printf("commands: [md5 | sha256]\n");
	ft_printf("command opts: [-pqrs]\n");
}

void debugmd5out(void)
{
	ft_printf("MD5 (\"Example\") = 0123456789abcdef0123456789abcdef\n");
}

void debugsha256out(void)
{
	ft_printf("SHA256 (\"Example\") = 0123456789abcdef0123456789abcdef\n");
}


int main(int argc, char **argv)
{
	char *str;
	char buf[32];

	bzero(buf, 32);
	if (argc < 2)
		ft_ssl_md5_usage();
	else
	{
		int ind;
		ft_printf("%d\n", (ind = get_funct_index(argv[1])));
		if (ind >= 0)
			command_funcs[ind]();
		else
			ft_printf("ft_ssl_md5: Error: %s is not a valid command, see `ft_ssl_md5 help'\n", argv[1]);
	}
	return(0);
}
