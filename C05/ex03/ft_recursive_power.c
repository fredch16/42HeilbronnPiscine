/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:20:50 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 19:15:52 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

#include <stdio.h>
int	main()
{
	printf("number is %d\n", ft_recursive_power(6, 3));
	printf("number is %d\n", ft_recursive_power(6, 0));
	printf("number is %d\n", ft_recursive_power(6, 1));
	printf("number is %d\n", ft_recursive_power(6, 2));
}