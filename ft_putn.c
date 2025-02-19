/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:25:32 by pahernan          #+#    #+#             */
/*   Updated: 2025/02/19 12:27:06 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
