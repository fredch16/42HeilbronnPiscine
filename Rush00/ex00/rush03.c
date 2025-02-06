/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashuvalo <ashuvalo@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 02:19:09 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/01/18 18:01:42 by ashuvalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_draw_line(int x, int y, int i, char *symbols)
{
	int	j;

	j = 1;
	while (j <= x)
	{
		if ((i == 1 && j == 1) || (j == 1 && i == y))
		{
			ft_putchar(symbols[0]);
		}
		else if ((j == x && i == 1) || (i == y && j == x))
		{
			ft_putchar(symbols[1]);
		}
		else if (i == 1 || j == 1 || i == y || j == x)
		{
			ft_putchar(symbols[2]);
		}
		else
		{
			ft_putchar(symbols[3]);
		}
		j++;
	}
}

void	rush(int x, int y)
{
	char	*symbols;
	int		i;

	symbols = "ACB ";
	i = 1;
	while (i <= y)
	{
		ft_draw_line(x, y, i, symbols);
		ft_putchar('\n');
		i++;
	}
}
