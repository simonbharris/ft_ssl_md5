#include <ft_ssl.h>

void	ft_ssl_usage(void)
{
    int i;

    i = 0;
    ft_printf("usage: ft_ssl command [-");
    while (g_ssl_opts[i].c && g_ssl_opts[i].c != 's')
        ft_printf("%c", g_ssl_opts[i++].c);
    ft_printf("] [-s string] [files ...]\n");

}

void	ft_ssl_help(void)
{
    int i;

    i = 0;
    ft_ssl_usage();
    ft_printf("Commands:\n");
    while (g_ssl_functs[i].name)
        ft_printf("   %s\n", g_ssl_functs[i++].name);
    exit(0);
}