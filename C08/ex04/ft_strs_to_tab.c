/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:57:57 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/30 00:45:56 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a function that takes an array of string as argument 
and the size of this array.
• Here’s how it should be prototyped:
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
• It will transform each element of av into a structure.
• The structure will be defined in the ft_stock_str.h file that
we will provided, like this:
◦ size being the length of the string;
◦ str being the string;
◦ copy being a copy of the string;
• It should keep the order of av.
• The returned array should allocated in memory and its last
element’s str set to 0, this will mark the end of the array.
• It should return a NULL pointer if an error occurs.
• We’ll test your function with our ft_show_tab (next exercise). 
Make it work according to this !
*/

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		size;
	int		i;
	char	*dup;

	i = 0;
	size = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*stru;

	i = 0;
	stru = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!stru)
		return (NULL);
	while (i < ac)
	{
		stru[i].size = ft_strlen(av[i]);
		stru[i].str = av[i];
		stru[i].copy = ft_strdup(av[i]);
		if (!stru[i].copy)
		{
			while (i > 0)
				free(stru[--i].copy);
			free(stru);
			return (NULL);
		}
		i++;
	}
	stru[i].str = 0;
	return (stru);
}
