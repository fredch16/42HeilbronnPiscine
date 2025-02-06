/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 05:39:03 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/20 00:08:26 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	print_two_digits(int n)
{
	ft_putchar((n / 10) + '0');
	ft_putchar((n % 10) + '0');
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			print_two_digits(first);
			ft_putchar(' ');
			print_two_digits(second);
			if (!(first == 98 && second == 99))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			second++;
		}
		first++;
	}
}
