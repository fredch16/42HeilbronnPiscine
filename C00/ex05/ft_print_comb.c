/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:48:37 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/19 06:47:57 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

static void	print_three_digits(char one, char two, char three, bool is_last)
{
	char	nb[3];

	nb[0] = one;
	nb[1] = two;
	nb[2] = three;
	write(1, nb, 3);
	if (!is_last)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	one;
	char	two;
	char	three;
	bool	is_last;

	one = '0';
	while (one <= '7')
	{
		two = one + 1;
		while (two <= '8')
		{
			three = two + 1;
			while (three <= '9')
			{
				is_last = (one == '7' && two == '8' && three == '9');
				print_three_digits(one, two, three, is_last);
				three++;
			}
			two++;
		}
		one++;
	}
}

// int main()
// {
// 	ft_print_comb();
// 	return (0);
// }