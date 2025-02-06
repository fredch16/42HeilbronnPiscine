/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:55:15 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/23 01:22:52 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;

	if (!str)
		return (0);
	nbr = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	nbr = nbr * sign;
	return (nbr);
}
