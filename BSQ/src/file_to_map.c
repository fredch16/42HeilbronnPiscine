/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:29:49 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 07:15:23 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

t_map	*content_to_map(char *content)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->cols = 0;
	map->rows = 0;
	if (!verify_map(content, map))
	{
		ft_putstr_fd("map error\n", 2);
		free(map);
		return (NULL);
	}
	map->grid = create_map(map);
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	fill_map(content, map);
	return (map);
}

char	**create_map(t_map *map)
{
	char	**grid;
	int		i;

	grid = (char **)malloc(sizeof(char *) * (map->rows + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		grid[i] = (char *)malloc(sizeof(char) * (map->cols + 1));
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		ft_memset(grid[i], 0, map->cols + 1);
		i++;
	}
	grid[map->rows] = NULL;
	return (grid);
}

void	fill_map(char *str, t_map *map)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	j++;
	while (c < map->rows)
	{
		i = 0;
		while (str[j] != '\n' && str[j] != '\0')
		{
			if (i < map->cols)
				map->grid[c][i++] = str[j];
			j++;
		}
		if (i < map->cols)
			map->grid[c][i] = '\0';
		j++;
		c++;
	}
}
