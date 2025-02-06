/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:58:56 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/26 18:05:27 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int	count_visible_from_left(int **grid, int row)
{
	int	max_height;
	int	visible_count;
	int	col;

	max_height = 0;
	visible_count = 0;
	col = 0;
	while (col < GRID_SIZE)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visible_count++;
		}
		col++;
	}
	return (visible_count);
}

int	count_visible_from_right(int **grid, int row)
{
	int	max_height;
	int	visible_count;
	int	col;

	max_height = 0;
	visible_count = 0;
	col = GRID_SIZE - 1;
	while (col >= 0)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visible_count++;
		}
		col--;
	}
	return (visible_count);
}

int	count_visible_from_top(int **grid, int col)
{
	int	max_height;
	int	visible_count;
	int	row;

	max_height = 0;
	visible_count = 0;
	row = 0;
	while (row < GRID_SIZE)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visible_count++;
		}
		row++;
	}
	return (visible_count);
}

int	count_visible_from_bottom(int **grid, int col)
{
	int	max_height;
	int	visible_count;
	int	row;

	max_height = 0;
	visible_count = 0;
	row = GRID_SIZE - 1;
	while (row >= 0)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visible_count++;
		}
		row--;
	}
	return (visible_count);
}
