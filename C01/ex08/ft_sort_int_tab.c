/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:15:01 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/22 21:34:45 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
#include <stdio.h>

int	main(void)
{
	int	tab[] = {5, 3, 8, 6, 2, 7, 4, 1};
	int	size = sizeof(tab) / sizeof(tab[0]);
	int	i;

	ft_sort_int_tab(tab, size);
	for (i = 0; i < size; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
	return (0);
}