#include <ft_ssl.h>

int			get_ft_ssl_opt(char c)
{
	int i = 0;
	while (g_ssl_opts[i].c)
	{
		if (c == g_ssl_opts[i].c)
			return (g_ssl_opts[i].flag);
			i++;
	}
	return (0);
}

void		load_ftssl_opts(char **argv, int *ai)
{
	int i = 0;
	int j = 0;
	int val = 0;

	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		j = 0;
		while (argv[i][++j])
		{
			if ((val = get_ft_ssl_opt(argv[i][j])) > 0)
				g_ft_ssl_flags |= val;
			else
			{
				ft_printf("ft_ssl: Error: Invalid flag: %c", argv[i][j]);
				ft_ssl_usage();
			}
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