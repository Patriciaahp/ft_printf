/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:36:32 by pahernan          #+#    #+#             */
/*   Updated: 2025/02/12 12:35:01 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
void ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	ft_putchar(nb + '0');
}

void ft_unsignedputnbr(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_unsignedputnbr(nb / 10);
		nb = nb % 10;
	}
	ft_putchar(nb + '0');
}

void ft_puthex(unsigned long n, char *hexChars)
{

	if (n >= 16)
	{
		ft_puthex(n / 16, hexChars);
		n = n % 16;
	}

	ft_putchar(hexChars[n]);
}

void ft_putpointer(void *ptr)
{
	unsigned long n;
	n = (unsigned long)ptr;
	ft_putstr("0x");
	if (n == 0)
	{
		ft_putchar('0');
		return;
	}
	ft_puthex(n, "0123456789abcdef");
}

int ft_printf(char *str, ...)
{
	int i;
	int size;
	va_list args;
	va_start(args, str);

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			switch (str[i])
			{
			case 'c':
				ft_putchar(va_arg(args, int));
				size++;
				break;
			case 's':
				ft_putstr(va_arg(args, char *));
				break;
			case 'd':
			case 'i':
				ft_putnbr(va_arg(args, int));
				break;
			case '%':
				ft_putchar('%');
				size++;
				break;
			case 'u':
				ft_unsignedputnbr(va_arg(args, unsigned int));
				size++;
				break;
			case 'x':
				ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
				size++;
				break;
			case 'X':
				ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
				size++;
				break;
			case 'p':
				ft_putpointer(va_arg(args, void *));
				size++;
				break;
			default:
				ft_putchar('%');
				ft_putchar(str[i]);
				size += 2;
				break;
			}
		}
		else
		{
			ft_putchar(str[i]);
			size++;
		}
		i++;
	}

	va_end(args);
	return (size);
}

/*#include <stdio.h>

int main(void)
{
	int num = 42;
	int *ptr = &num;

	ft_printf("Hola %s %c %i %% %u %p %X %x\n", "ft_mundo", '!', -42, -42, ptr, num, num);
	printf("Hola %s %c %i %% %u %p %X %x\n", "mundo", '!', -42, -42, ptr, num, num);
}*/