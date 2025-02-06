/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 08:32:26 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/21 01:33:07 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*ogstr;

	ogstr = str;
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'Z'))
			*str += 32;
		str++;
	}
	return (ogstr);
}
