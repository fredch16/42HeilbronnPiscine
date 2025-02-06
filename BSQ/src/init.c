/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:43:55 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 17:05:02 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// new : 
// old: ""
// "first buffer"
// "first buffer second buffer"


#include "../include/bsq.h"

void	init_data(t_data *data)
{
	data->bsq = NULL;
	data->map = NULL;
}

void	init_sq(t_sq *sq)
{
	sq->len = 0;
	sq->x = 0;
	sq->y = 0;
}

void	free_map(t_map *map)
{
	int	c;

	c = 0;
	while (c < map->rows)
	{
		free(map->grid[c]);
		c++;
	}
	free(map->grid);
	free(map);
}
