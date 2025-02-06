/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:44:49 by swied             #+#    #+#             */
/*   Updated: 2025/02/05 06:46:35 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

char	**put_solution(t_map *map, t_sq *sq)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = sq->y;
	b = sq->x;
	c = 0;
	d = 0;
	while (d < sq->len)
	{
		while (c < sq->len)
		{
			map->grid[a][b] = map->full;
			b++;
			c++;
		}
		c = 0;
		b = sq->x;
		a++;
		d++;
	}
	return (map->grid);
}
