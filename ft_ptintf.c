/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahernan <pahernan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:36:32 by pahernan          #+#    #+#             */
/*   Updated: 2025/01/29 09:36:00 by pahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;

		if (s1[i] == '\0' || s2[i] == '\0' || !(s1[i] == s2[i]))
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	return (0);
}

int ft_to_string (const char *str)
{
if (ft_strcmp(str, "%c") == 0)
		return 1;
    else if (ft_strcmp(str, "%s") == 0)
		return 2;
	else if (ft_strcmp(str, "%p") == 0)
		return 3;
	else if (ft_strcmp(str, "%d") == 0)
		return 4;
	else if (ft_strcmp(str, "%i") == 0)
		return 5;
	else if (ft_strcmp(str, "%u") == 0)
		return 6;
	else if (ft_strcmp(str, "%x") == 0)
		return 7;
	else if (ft_strcmp(str, "%X") == 0)
		return 8;
	else
		return 0;
}

void ft_putchar (char c)
{
	write(1, &c, 1);
}

void ft_printf (char *b, int c)
{
	int type = ft_to_string(b);

switch (type)
{
case 1:
ft_putchar(c);
	break;

default:
	break;
}
}

int main (void)
{
	ft_printf("%c", 'c');
}