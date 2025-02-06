/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:57:21 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/21 01:33:18 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*ogstr;

	ogstr = str;
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z'))
			*str -= 32;
		str++;
	}
	return (ogstr);
}
