/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swied <swied@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:31:17 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/04 00:55:22 by swied            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

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
	int		i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
		dst[i++] = '\0';
	return (dst);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
