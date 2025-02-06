/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:59:39 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/21 17:39:47 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_alnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_word_start;

	i = 0;
	is_word_start = 1;
	while (str[i] != '\0')
	{
		if (is_alnum(str[i]))
		{
			if (is_word_start)
				str[i] = to_upper(str[i]);
			else
				str[i] = to_lower(str[i]);
			is_word_start = 0;
		}
		else
			is_word_start = 1;
		i++;
	}
	return (str);
}
