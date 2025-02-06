/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 01:50:47 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/29 17:58:24 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a function that returns the result of the conversion of 
the string nbr from a base base_from to a base base_to.
• nbr, base_from, base_to may be not writable.
• nbr will follow the same rules as ft_atoi_base (from an other module).
Beware of ’+’, ’-’ and whitespaces.
• The number represented by nbr must fit inside an int.
• If a base is wrong, NULL should be returned.
• The returned number must be prefix only by a single and uniq
’-’ if necessary, no whitespaces, no ’+’.
• Here’s how it should be prototyped :
*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int		ft_strlen(char *str);
int		is_valid_base(char *base);
int		get_base_value(char c, char *base);
int		skip_whitespace_and_sign(char **str);
int		ft_atoi_base(char *str, char *base);

void	ft_itoa_base(int nbr, char *base, int *i, char *outstr)
{
	if (nbr == -2147483648)
	{
		outstr[(*i)++] = '-';
		ft_itoa_base(-(nbr / ft_strlen(base)), base, i, outstr);
		ft_itoa_base(-(nbr % ft_strlen(base)), base, i, outstr);
		return ;
	}
	else if (nbr < 0)
	{
		outstr[(*i)++] = '-';
		nbr = -nbr;
	}
	if (nbr >= (int)ft_strlen(base))
	{
		ft_itoa_base(nbr / ft_strlen(base), base, i, outstr);
		ft_itoa_base(nbr % ft_strlen(base), base, i, outstr);
	}
	else
		outstr[(*i)++] = base[nbr];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec_nbr;
	int		i;
	char	*outstr;

	if (!is_valid_base(base_from))
		return (NULL);
	if (!is_valid_base(base_to))
		return (NULL);
	outstr = (char *)malloc(33 * sizeof(char));
	if (!outstr)
		return (NULL);
	i = 0;
	while (i < 33)
		outstr[i++] = '\0';
	i = 0;
	dec_nbr = ft_atoi_base(nbr, base_from);
	ft_itoa_base(dec_nbr, base_to, &i, outstr);
	return (outstr);
}

// int main()
// {
// 	// char *result = ft_convert_base("", "01", "0123456789");
// // 1111111111111111111111111111111
// 	printf("Converted number: %s\n", result);
// 	free(result); // Free the allocated memory
// 	return (0);
// }
// int main()
// {
// 	char *result;

// 	// Test with binary to decimal
// 	result = ft_convert_base("1010", "01", "0123456789");
// 	printf("Binary to Decimal: %s\n", result);
// 	free(result);

// 	// Test with decimal to binary
// 	result = ft_convert_base("10", "0123456789", "01");
// 	printf("Decimal to Binary: %s\n", result);
// 	free(result);

// 	// Test with hexadecimal to decimal
// 	result = ft_convert_base("A", "0123456789ABCDEF", "0123456789");
// 	printf("Hexadecimal to Decimal: %s\n", result);
// 	free(result);

// 	// Test with decimal to hexadecimal
// 	result = ft_convert_base("10", "0123456789", "0123456789ABCDEF");
// 	printf("Decimal to Hexadecimal: %s\n", result);
// 	free(result);

// 	// Test with invalid base
// 	result = ft_convert_base("10", "0123456789", "0123446789");
// 	printf("Invalid Base: %s\n", result);

// 	// Test with invalid base because OF WHITESPACE IN THE BASE????????
// 	result = ft_convert_base("10", "0123456789 ", "0123446789");
// 	printf("Invalid Base WITH SPACE: %s\n", result);

// 	// Test with negative number
// 	result = ft_convert_base("-10", "0123456789", "01");
// 	printf("Negative Decimal to Binary: %s\n", result);
// 	free(result);

// 	// Test with leading whitespaces
// 	result = ft_convert_base("   +-+-++++10", "0123456789", "01");
// 	printf("Leading Whitespaces: %s\n", result);
// 	free(result);

// 	// Test with leading plus sign
// 	result = ft_convert_base("+10", "0123456789", "01");
// 	printf("Leading Plus Sign: %s\n", result);
// 	free(result);

// 	// Test with leading minus sign
// 	result = ft_convert_base("-10", "0123456789", "01");
// 	printf("Leading Minus Sign: %s\n", result);
// 	free(result);

// 	// Test with INT_MAX
// 	result = ft_convert_base("2147483647", "0123456789", "01");
// 	printf("INT_MAX to Binary: %s\n", result);
// 	free(result);

// 	// Test with INT_MIN
// 	result = ft_convert_base("-2147483648", "0123456789", "01");
// 	printf("INT_MIN to Binary: %s\n", result);
// 	free(result);

// 	return 0;
// }