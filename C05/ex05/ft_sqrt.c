/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:46:56 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/28 21:47:48 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	sqrt = 1;
	while (sqrt < nb / sqrt)
		sqrt++;
	if (sqrt == nb / sqrt && nb % sqrt == 0)
		return (sqrt);
	else
		return (0);
}