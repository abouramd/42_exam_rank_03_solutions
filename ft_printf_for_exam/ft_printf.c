/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:29:34 by abouramd          #+#    #+#             */
/*   Updated: 2023/02/06 17:29:36 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	put_str(int *len, char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		*len += write(1, "(null)", 6);
	else
	{
		while (s[i])
			i++;
		*len += write(1, s, i);
	}
}

void	put_nbr(int *len, long n)
{
    if (0 > n)
    {
        *len += write(1, "-", 1);
        n *= -1
    }
	if (n > 9)
		put_nbr(len, n / 10);
	*len += write(1, &"0123456789"[n % 10], 1);
}

void	hex(int *len, unsigned int n)
{
	if (n > 15)
		hex(len, n / 16);
	*len += write(1, &"0123456789abcdef"[n % 16], 1);
}

int	ft_printf(const char *str, ...)
{
    va_list    a;
    int        len;
	size_t	i;

	i = 0;
	len = 0;
	va_start(a, str);
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 's' || str[i + 1] == 'd' || str[i + 1] == 'x'))
		{
			i++;
			if (str[i] == 's')
				put_str(&len, va_arg(a, char *));
			else if (str[i] == 'd')
				put_nbr(&len, va_arg(a, int));
			else if (str[i] == 'x')
				hex(&len, va_arg(a, unsigned int));
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(a);
	return (len);
}

// int	main(void)
// {
// 	ft_printf("%d\n", ft_printf("%s %x %d --", "toto",  2147483647, -1));
// 		printf("%d\n",    printf("%s %x %d --", "toto", 2147483647, -1));
// }
