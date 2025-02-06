/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:50:33 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/26 20:33:43 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include <stdlib.h>
# include <unistd.h>

# define GRID_SIZE 4

typedef struct s_puzzle
{
	int	**grid;
	int	*clues;
}	t_puzzle;

int		count_visible_from_left(int **grid, int row);
int		count_visible_from_right(int **grid, int row);
int		count_visible_from_top(int **grid, int col);
int		count_visible_from_bottom(int **grid, int col);
void	print_grid(int **grid);
int		**init_grid(void);
void	free_grid(int **grid);
int		is_valid(t_puzzle *puzzle, int row, int col, int num);
int		solve(t_puzzle *puzzle, int row, int col);
void	ft_putstr(char *str);
int		*parse_input(char *input);
int		**init_grid(void);
void	free_grid(int **grid);
void	print_grid(int **grid);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

#endif
