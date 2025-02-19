/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:36:32 by pahernan          #+#    #+#             */
/*   Updated: 2025/02/19 12:31:43 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *size)
{
	write(1, &c, 1);
	(*size)++;
}

void	ft_putstr(char *s, int *size)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		(*size)++;
	}
}

void	ft_puthex(unsigned long n, char *hexChars, int *size)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, hexChars, size);
		n = n % 16;
	}
	ft_putchar(hexChars[n], size);
}

void	ft_putpointer(void *ptr, int *size)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*size += 5;
		return ;
	}
	ft_putstr("0x", size);
	ft_puthex(n, "0123456789abcdef", size);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			size;
	va_list		args;

	va_start(args, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 'c')
				ft_putchar(va_arg(args, int), &size);
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *), &size);
			else if (str[i] == 'i')
				ft_putnbr(va_arg(args, int), &size);
			else if (str[i] == 'd')
				ft_putnbr(va_arg(args, int), &size);
			else if (str[i] == '%')
				ft_putchar('%', &size);
			else if (str[i] == 'u')
				ft_unsignedputnbr(va_arg(args, unsigned int), &size);
			else if (str[i] == 'x')
				ft_puthex(va_arg(args, unsigned int),
					"0123456789abcdef", &size);
			else if (str[i] == 'X')
				ft_puthex(va_arg(args, unsigned int),
					"0123456789ABCDEF", &size);
			else if (str[i] == 'p')
				ft_putpointer(va_arg(args, void *), &size);
			else
			{
				ft_putchar('%', &size);
				ft_putchar(str[i], &size);
			}
		}
		else
			ft_putchar(str[i], &size);
		i++;
	}
	va_end(args);
	return (size);
}
