/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:07:55 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/26 18:05:25 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

void	print_grid(int **grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < GRID_SIZE - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	**init_grid(void)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	grid = (int **)malloc(sizeof(int *) * GRID_SIZE);
	while (i < GRID_SIZE)
	{
		grid[i] = (int *)malloc(sizeof(int) * GRID_SIZE);
		j = 0;
		while (j < GRID_SIZE)
			grid[i][j++] = 0;
		i++;
	}
	return (grid);
}

void	free_grid(int **grid)
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
