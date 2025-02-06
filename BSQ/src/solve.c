/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:21:47 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 06:18:44 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	update_bsq(t_sq *sq, int currmax, int x, int y)
{
	sq->len = currmax;
	sq->x = x;
	sq->y = y;
}

int	check_obstacles(t_data *data, int x, int y, int currmax)
{
	int	i;
	int	j;

	i = 0;
	while (i <= currmax)
	{
		if (data->map->grid[y + currmax][x + i] != data->map->empty)
		{
			return (1);
		}
		i++;
	}
	j = 0;
	while (j <= currmax)
	{
		if (data->map->grid[y + j][x + currmax] != data->map->empty)
		{
			return (1);
		}
		j++;
	}
	return (0);
}

void	check_sq(t_data *data, int x, int y)
{
	int	obst;
	int	currmax;

	obst = 0;
	currmax = 1;
	if (data->map->grid[y][x] != data->map->empty)
		return ;
	while (!obst)
	{
		if ((x + currmax) >= data->map->cols || (y + currmax)
			>= data->map->rows)
			break ;
		if (check_obstacles(data, x, y, currmax))
			obst = 1;
		if (!obst)
			currmax++;
	}
	if (currmax > data->bsq->len)
		update_bsq(data->bsq, currmax, x, y);
}

int	find_bsq(t_data *data)
{
	int	x;
	int	y;

	init_sq(data->bsq);
	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			check_sq(data, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

int	solve(t_data *data)
{
	t_sq	*bsq;

	bsq = (t_sq *)malloc(sizeof(t_sq));
	if (!bsq)
		return (-1);
	data->bsq = bsq;
	if (find_bsq(data))
		return (1);
	return (-2);
}
