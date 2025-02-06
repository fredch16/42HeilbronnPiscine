/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:42:51 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/27 16:43:07 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	i = 0;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("res is %d\n", ft_iterative_power(6, 3));
// 	return (0);
// }