/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 01:26:18 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/02 03:56:06 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Write a function that will concatenate all the strings pointed 
by strs separated by sep.
• size is the number of strings in strs
• if size is 0, you must return an empty string that you can free().
• Here’s how it should be prototyped :
*/
#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (original_dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*original;

	original = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = 0;
	return (original);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*strcatter(int size, char **strs, char *sep, char *result)
{
	int	i;

	i = 1;
	while (i < size)
	{
		ft_strcat(result, sep);
		ft_strcat(result, strs[i]);
		i++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	char	*result;

	total_len = 0;
	i = 0;
	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result != NULL)
			result[0] = '\0';
		return (result);
	}
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += (size - 1) * ft_strlen(sep) + 1;
	result = (char *)malloc(total_len);
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, strs[0]);
	strcatter(size, strs, sep, result);
	return (result);
}

// int	main(void)
// {
// 	char	*strs[] = {"Hello", "world", "this", "is", "a", "test"};
// 	char	*sep = " ";
// 	char	*result;

// 	// Test with multiple strings
// 	result = ft_strjoin(6, strs, sep);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	// Test with no strings
// 	result = ft_strjoin(0, strs, sep);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	// Test with one string
// 	result = ft_strjoin(1, strs, sep);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	// Test with different separator
// 	sep = "-";
// 	result = ft_strjoin(6, strs, sep);
// 	printf("Result: %s\n", result);
// 	free(result);

// 	return (0);
// }

int main() {
    char *strs[] = {"", "Hello", "", "World"};
    char *sep = "-";
    int size = 4;
    printf ("%s", "test\n");
    // Gib das Ergebnis aus
    printf("%s\n", ft_strjoin(size, strs, sep));
    return 0;
}