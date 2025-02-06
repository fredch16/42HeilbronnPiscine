/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:06:31 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/29 01:47:07 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	i;
	int	*array;

	if (min >= max)
		return (NULL);
	range = max - min;
	array = (int *)malloc(sizeof(int) * range);
	if (!array)
		return (NULL);
	i = 0;
	while (i < range)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
