/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:44:59 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/21 00:04:38 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_byte_hex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	print_address(unsigned long long addr)
{
	char	hex[16];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		hex[i] = base[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, hex, 16);
	write(1, ": ", 2);
}

void	print_memory_line(unsigned char *ptr, unsigned int i, unsigned int size)
{
	unsigned int	j;

	print_address((unsigned long long)(ptr + i));
	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			print_byte_hex(ptr[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
	j = 0;
	while (j < 16 && (i + j) < size)
	{
		if (ptr[i + j] >= 32 && ptr[i + j] <= 126)
			write(1, &ptr[i + j], 1);
		else
			write(1, ".", 1);
		j++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	if (size == 0)
		return (addr);
	i = 0;
	while (i < size)
	{
		print_memory_line(ptr, i, size);
		i += 16;
	}
	return (addr);
}
