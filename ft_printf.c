/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:36:32 by pahernan          #+#    #+#             */
/*   Updated: 2025/02/19 10:22:20 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int size)
{
	write(1, &c, 1);
	size++;
	return (size);
}

int	ft_putstr(char *s, int size)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		size++;
	}
	return (size);
}

int	ft_putnbr(int nb, int size)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		size = 11;
		return (size);
	}
	if (nb < 0)
	{
		ft_putchar('-', size);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, size);
		nb = nb % 10;
	}
	ft_putchar(nb + '0', size);
	return (size);
}

int	ft_unsignedputnbr(unsigned int nb, int size)
{
	if (nb >= 10)
	{
		ft_unsignedputnbr(nb / 10, size);
		nb = nb % 10;
	}
	ft_putchar(nb + '0', size++);
	return (size);
}

int	ft_puthex(unsigned long n, char *hexChars, int size)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, hexChars, size);
		n = n % 16;
	}
	ft_putchar(hexChars[n], size);
	return (size);
}

int	ft_putpointer(void *ptr, int size)
{
	unsigned long	n;

	n = (unsigned long)ptr;
	ft_putstr("0x", size);
	if (n == 0)
	{
		ft_putchar('0', size);
		return (size);
	}
	ft_puthex(n, "0123456789abcdef", size);
	return (size);
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
				ft_putchar(va_arg(args, int), size);
			else if (str[i] == 's')
				ft_putstr(va_arg(args, char *), size);
			else if (str[i] == 'i')
				ft_putnbr(va_arg(args, int), size);
			else if (str[i] == 'd')
				ft_putnbr(va_arg(args, int), size);
			else if (str[i] == '%')
				ft_putchar('%', size);
			else if (str[i] == 'u')
				ft_unsignedputnbr(va_arg(args, unsigned int), size);
			else if (str[i] == 'x')
				ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", size);
			else if (str[i] == 'X')
				ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", size);
			else if (str[i] == 'p')
				ft_putpointer(va_arg(args, void *), size);
			else
			{
				ft_putchar('%', size);
				ft_putchar(str[i], size);
			}
		}
		else
		{
			ft_putchar(str[i], size);
		}
		i++;
	}
	va_end(args);
	return (size);
}

/*#include <stdio.h>

int main(void)
{
	int num = 2;
	int *ptr = &num;
	char *str = "mundo";

	ft_printf("Hola %s %c %i %% %u %p %X %x %d\n", str, '!', num, num, ptr, num, num, num);
	printf("Hola %s %c %i %% %u %p %X %x\n %d", str, '!', num, num, ptr, num, num, num);
}*/