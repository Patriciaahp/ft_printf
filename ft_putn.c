/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:25:32 by pahernan          #+#    #+#             */
/*   Updated: 2025/02/20 09:50:46 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *size)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*size += 11;
		return ;
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
}

void	ft_unsignedputnbr(unsigned int nb, int *size)
{
	if (nb >= 10)
	{
		ft_unsignedputnbr(nb / 10, size);
		nb = nb % 10;
	}
	ft_putchar(nb + '0', size);
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
