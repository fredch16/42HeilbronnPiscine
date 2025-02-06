/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:56:04 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/28 16:14:15 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define SIZE 10

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution(int *board)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	is_safe(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col
			|| board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int col, int *count)
{
	int	row;

	if (col == SIZE)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < SIZE)
	{
		if (is_safe(board, row, col))
		{
			board[col] = row;
			solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[SIZE];
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < SIZE)
	{
		board[i] = 0;
		i++;
	}
	solve(board, 0, &count);
	return (count);
}

// int	main(void)
// {
// 	int	solutions;

// 	solutions = ft_ten_queens_puzzle();
// 	return (0);
// }