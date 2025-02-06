/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:30:44 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 07:33:50 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			write(1, &map->grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	bsq(t_data *data, int ac, char *av)
{
	init_data(data);
	data->map = get_map(av, ac);
	if (!data->map)
		return (1);
	if (solve(data) >= 0)
	{
		data->map->grid = put_solution(data->map, data->bsq);
		print_map(data->map);
	}
	free_map(data->map);
	free(data->bsq);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac && bsq(&data, ac, av[i]))
		{
			i++;
			if (i != ac)
				ft_putstr_fd("\n", 1);
		}
		if (i < ac)
			return (1);
	}
	else
		return (bsq(&data, 1, NULL) - 1);
	return (0);
}
