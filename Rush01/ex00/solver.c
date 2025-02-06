/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:27:00 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 02:48:47 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "solver.h"

int	is_in_row_or_col(int **grid, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_visibility(t_puzzle *puzzle, int row, int col)
{
	if (col == GRID_SIZE - 1)
	{
		if (count_visible_from_left(puzzle->grid, row)
			!= puzzle->clues[GRID_SIZE * 2 + row]
			|| count_visible_from_right(puzzle->grid, row)
			!= puzzle->clues[GRID_SIZE * 3 + row])
			return (0);
	}
	if (row == GRID_SIZE - 1)
	{
		if (count_visible_from_top(puzzle->grid, col) != puzzle->clues[col]
			|| count_visible_from_bottom(puzzle->grid, col)
			!= puzzle->clues[GRID_SIZE + col])
			return (0);
	}
	return (1);
}

int	is_valid(t_puzzle *puzzle, int row, int col, int num)
{
	if (is_in_row_or_col(puzzle->grid, row, col, num))
		return (0);
	puzzle->grid[row][col] = num;
	if (!check_visibility(puzzle, row, col))
	{
		puzzle->grid[row][col] = 0;
		return (0);
	}
	puzzle->grid[row][col] = 0;
	return (1);
}

int	solve(t_puzzle *puzzle, int row, int col)
{
	int	num;

	num = 1;
	if (row == GRID_SIZE)
		return (1);
	if (col == GRID_SIZE)
		return (solve(puzzle, row + 1, 0));
	while (num <= GRID_SIZE)
	{
		if (is_valid(puzzle, row, col, num))
		{
			puzzle->grid[row][col] = num;
			if (solve(puzzle, row, col + 1))
				return (1);
			puzzle->grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
