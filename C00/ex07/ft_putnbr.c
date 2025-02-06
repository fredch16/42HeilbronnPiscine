/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 06:10:08 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/19 06:36:15 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		return ;
	}
	ft_putchar(nb + '0');
	return ;
}

// int	main()
// {
// 	ft_putnbr(242);
// 	ft_putchar('\n');
// 	ft_putnbr(-2147483648);
// 	ft_putchar('\n');
// 	ft_putnbr(2147483647);
// 	ft_putchar('\n');
// 	ft_putnbr(-242);
// 	ft_putchar('\n');
// }