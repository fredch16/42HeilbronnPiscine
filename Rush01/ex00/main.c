/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:32:58 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/02 23:04:48 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int	main(int argc, char **argv)
{
	t_puzzle	puzzle;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	puzzle.clues = parse_input(argv[1]);
	if (!puzzle.clues)
		return (0);
	puzzle.grid = init_grid();
	if (!puzzle.grid)
	{
		free(puzzle.clues);
		ft_putstr("Error\n");
		return (0);
	}
	if (solve(&puzzle, 0, 0))
		print_grid(puzzle.grid);
	else
		ft_putstr("Error\n");
	free(puzzle.clues);
	free_grid(puzzle.grid);
	return (0);
}
