/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:36:32 by pahernan          #+#    #+#             */
/*   Updated: 2025/02/19 12:55:22 by pahernan         ###   ########.fr       */
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

void ft_types(va_list args, char type, int *size)
{
	if (type == 'c')
	ft_putchar(va_arg(args, int), size);
else if (type == 's')
	ft_putstr(va_arg(args, char *), size);
else if (type == 'i')
	ft_putnbr(va_arg(args, int), size);
else if (type == 'd')
	ft_putnbr(va_arg(args, int), size);
else if (type == '%')
	ft_putchar('%', size);
else if (type == 'u')
	ft_unsignedputnbr(va_arg(args, unsigned int), size);
else if (type == 'x')
	ft_puthex(va_arg(args, unsigned int),
		"0123456789abcdef", size);
else if (type == 'X')
	ft_puthex(va_arg(args, unsigned int),
		"0123456789ABCDEF", size);
else if (type == 'p')
	ft_putpointer(va_arg(args, void *), size);
else
{
	ft_putchar('%', size);
	ft_putchar(type, size);
}
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
			ft_types(args, str[i], &size);
		}
		else
			ft_putchar(str[i], &size);
		i++;
	}
	va_end(args);
	return (size);
}
