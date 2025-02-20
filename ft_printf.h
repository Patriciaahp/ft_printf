/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:14:01 by pahernan          #+#    #+#             */
/*   Updated: 2025/02/20 09:50:01 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c, int *size);
void	ft_putstr(char *s, int *size);
void	ft_types(va_list args, char type, int *size);
void	ft_putnbr(int nb, int *size);
void	ft_unsignedputnbr(unsigned int nb, int *size);
void	ft_puthex(unsigned long n, char *hexChars, int *size);
void	ft_putpointer(void *ptr, int *size);
int		ft_printf(const char *str, ...);

#endif
