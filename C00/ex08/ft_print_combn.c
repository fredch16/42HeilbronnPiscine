/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:22:52 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/20 00:11:36 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	print_current_combination(int *digits, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = digits[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

bool	next_combination(int *digits, int n)
{
	int	idx;
	int	j;

	idx = n - 1;
	while (idx >= 0)
	{
		if (digits[idx] < 9 - (n - 1 - idx))
		{
			digits[idx]++;
			j = idx + 1;
			while (j < n)
			{
				digits[j] = digits[j - 1] + 1;
				j++;
			}
			return (true);
		}
		idx--;
	}
	return (false);
}

void	ft_print_combn(int n)
{
	int	digits[10];
	int	i;

	i = 0;
	while (i < n)
	{
		digits[i] = i;
		i++;
	}
	print_current_combination(digits, n);
	while (next_combination(digits, n))
	{
		write(1, ", ", 2);
		print_current_combination(digits, n);
	}
}
