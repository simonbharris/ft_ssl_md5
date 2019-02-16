//
// Created by Simon Harris on 12/1/18.
//

#include <libft.h>

void	ft_putupper(char *str)
{
	while (*str)
	{
		*str >= 'a' && *str <= 'z' ? ft_putchar(*str - 32) : ft_putchar(*str);
		str++;
	}
}