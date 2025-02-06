/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:17:06 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/29 17:57:58 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
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

int	get_base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	skip_whitespace_and_sign(char **str)
{
	int	sign;

	sign = 1;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nbr;
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (!is_valid_base(base))
		return (0);
	nbr = 0;
	sign = skip_whitespace_and_sign(&str);
	while (*str && (get_base_value(*str, base) != -1))
	{
		nbr = nbr * base_len + get_base_value(*str, base);
		str++;
	}
	return (nbr * sign);
}

// int	main(void)
// {
// 	char	str[] = "2147483647"; // INT_MAX in decimal
// 	char 	str2[]  = "-10000000000000000000000000000000";
// 	char	base[] = "0123456789"; // Decimal base
// 	char	base2[] = "01"; // Binary base
// 	char	str3[] = "123abc ";

// 	printf("The result is: %d\n", ft_atoi_base(str2, base2));
// 	printf("The result is: %d\n", ft_atoi_base(str3, base));
// 	return (0);
// }