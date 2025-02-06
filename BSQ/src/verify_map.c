/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:09:13 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 07:15:47 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int	unique_three(char a, char b, char c)
{
	if (a == b || a == c || b == c)
		return (0);
	return (1);
}

int	verify_map_row(t_map *map, char *content, int *index, int row)
{
	int	col;

	col = 0;
	while (content[*index] != '\n' && content[*index] != '\0')
	{
		if (!((content[*index] == map->empty)
				|| (content[*index] == map->obst)))
			return (0);
		col++;
		(*index)++;
	}
	if (row == 0)
		map->cols = col;
	if ((row != 0) && col != map->cols)
		return (0);
	if (content[*index] == '\n')
		(*index)++;
	return (1);
}

int	verify_map_chars(t_map *map, char *content)
{
	int	row;
	int	index;

	row = 0;
	index = 0;
	while (content[index])
	{
		if (!verify_map_row(map, content, &index, row))
			return (0);
		row++;
	}
	if (row != map->rows)
		return (0);
	return (1);
}

int	verify_map(char *content, t_map *map)
{
	int		i;
	int		row_count;

	i = 0;
	row_count = 0;
	while (content[i] >= '0' && content[i] <= '9')
		row_count = row_count * 10 + (content[i++] - '0');
	map->rows = row_count;
	if (i == 0 || !is_printable(content[i]) || !is_printable(content[i + 1])
		|| !is_printable(content[i + 2]))
		return (0);
	map->empty = content[i];
	map->obst = content[i + 1];
	map->full = content[i + 2];
	if (!unique_three(map->empty, map->obst, map->full))
		return (0);
	if (content[i + 3] != '\n')
		return (0);
	if ((content[i + 4] != map->empty) && content[i + 4] != map->obst)
		return (0);
	if (!verify_map_chars(map, content + i + 4))
		return (0);
	return (1);
}
