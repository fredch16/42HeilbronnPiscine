/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:50:20 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/26 18:36:57 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int	is_valid_digit(char c)
{
	return (c >= '1' && c <= '9');
}

int	validate_input(char *str)
{
	int	i;
	int	num_counter;

	i = 0;
	num_counter = 0;
	while (str[i])
	{
		if (!((str[i] == ' ') || is_valid_digit(str[i])))
		{
			return (0);
		}
		if (is_valid_digit(str[i]))
			num_counter++;
		i++;
	}
	if (num_counter != GRID_SIZE * 4)
		return (0);
	if (ft_strlen(str) != (GRID_SIZE * 4 + GRID_SIZE * 4 - 1))
		return (0);
	return (1);
}

int	*input_to_clues(char *input)
{
	int	*clues;
	int	i;
	int	j;

	clues = (int *)malloc(sizeof(int) * GRID_SIZE * 4);
	if (!clues)
		return (NULL);
	i = 0;
	j = 0;
	while (i < GRID_SIZE * 4)
	{
		if (input[j + 1] != ' ' && input[j + 1] != '\0')
		{
			free(clues);
			return (NULL);
		}
		clues[i] = input[j] - '0';
		i++;
		j += 2;
	}
	return (clues);
}

int	*parse_input(char *input)
{
	int	*clues;

	if (!(validate_input(input)))
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	clues = input_to_clues(input);
	if (!clues)
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	return (clues);
}
