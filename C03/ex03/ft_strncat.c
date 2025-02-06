/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:56:00 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/26 18:04:37 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*d;
	const char		*s;
	unsigned int	i;

	d = dest;
	s = src;
	while (*d)
		d++;
	i = 0;
	while (i < nb && *s)
	{
		*d++ = *s++;
		i++;
	}
	*d = '\0';
	return (dest);
}
