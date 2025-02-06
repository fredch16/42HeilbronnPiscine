/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:50:49 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/21 17:55:25 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
