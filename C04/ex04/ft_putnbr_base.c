/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:18:44 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/29 02:29:45 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!is_valid_base(base))
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(-(nbr / ft_strlen(base)), base);
		ft_putnbr_base(-(nbr % ft_strlen(base)), base);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= (int)ft_strlen(base))
	{
		ft_putnbr_base(nbr / ft_strlen(base), base);
		ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	else
		write(1, &base[nbr], 1);
}

// int main(void)
// {
// 	ft_putnbr_base(42, "01"); // Binary
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "0123456789"); // Decimal
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "0123456789ABCDEF"); // Hexadecimal
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-42, "0123456789ABCDEF"); // Negative number
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "poneyvif"); // Custom base
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, ""); // Invalid base
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "0"); // Invalid base
// 	write(1, "\n", 1);
// 	ft_putnbr_base(42, "01234+6789"); // Invalid base
// 	write(1, "\n", 1);
// 	return (0);
// }