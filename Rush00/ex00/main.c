/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashuvalo <ashuvalo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 02:14:57 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/01/18 18:12:26 by ashuvalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	rush(int x, int y);

int	ft_atoi(char *input)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	if (*input == '-')
	{
		sign = -1;
		input++;
	}
	while (*input >= '0' && *input <= '9')
	{
		nb = nb * 10;
		nb = nb + *input - '0';
		input++;
	}
	nb = nb * sign;
	if (nb > INT_MAX)
		nb = INT_MAX;
	if (nb < INT_MIN)
		nb = INT_MIN;
	return ((int) nb);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
	{
		write(1, "Please give an x and a y value, be reasonable.\n", 47);
		return (0);
	}
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	rush(x, y);
	return (0);
}
