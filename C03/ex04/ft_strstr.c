/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:00:16 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/26 18:04:40 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*p1;
	char	*p2;

	if (!*to_find)
		return (str);
	while (*str)
	{
		p1 = str;
		p2 = to_find;
		while (*str && *p2 && (*str == *p2))
		{
			str++;
			p2++;
		}
		if (!*p2)
			return (p1);
		str = p1 + 1;
	}
	return (0);
}
