/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:56:30 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 07:46:59 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_printable(char c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char	*read_stdin(void)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_STDIN + 1));
	if (!buffer)
		return (0);
	bytes_read = read(0, buffer, BUFFER_STDIN);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (0);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}
