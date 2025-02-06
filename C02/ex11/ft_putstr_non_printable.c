/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 08:44:35 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/20 23:20:37 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	to_hex_digit(int value)
{
	if (value < 10)
		return ((char)('0' + value));
	return ((char)('a' + (value - 10)));
}

void	ft_print_hex(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar(to_hex_digit((c >> 4) & 0x0F));
	ft_putchar(to_hex_digit(c & 0x0F));
}

int	is_printable(unsigned char c)
{
	return (c >= 32 && c < 127);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (is_printable(c))
			ft_putchar(c);
		else
			ft_print_hex(c);
		i++;
	}
}
