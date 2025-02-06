/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:08:49 by fredchar          #+#    #+#             */
/*   Updated: 2025/01/28 23:42:24 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create a function that splits a string of character depending on another 
string of characters.
• You’ll have to use each character from the string charset as a separator.
• The function returns an array where each element of the array contains the 
address of a string wrapped between two separators. The last element of that
array should equal to 0 to indicate the end of the array.
• There cannot be any empty strings in your array.
Get your own conclusions accordingly.
• The string given as argument won’t be modifiable.
• Here’s how it should be prototyped :
char **ft_split(char *str, char *charset);
*/

#include <stdlib.h>
#include <stdio.h>

int	seperator(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int	ft_nbstr(char *str, char *charset)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && seperator(str[i], charset))
			i++;
		if (str[i] && !seperator(str[i], charset))
			nb++;
		while (str[i] && !seperator(str[i], charset))
			i++;
	}
	return (nb);
}

char	*ft_strndup(char *str, int n)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return (0);
	i = 0;
	while (i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		strslen;
	int		i;
	int		x;

	strslen = ft_nbstr(str, charset);
	strs = (char **)malloc((strslen + 1) * sizeof(char *));
	if (!strs)
		return (0);
	i = 0;
	while (i < strslen)
	{
		while (*str && seperator(*str, charset))
			str++;
		x = 0;
		while (str[x] && !seperator(str[x], charset))
			x++;
		strs[i] = ft_strndup(str, x);
		if (!strs[i])
			return (0);
		str += x;
		i++;
	}
	strs[i] = 0;
	return (strs);
}

// int	main(void)
// {
// 	char	**result;
// 	int		i;
// 	char	str1[] = "Hello, world! This is a test.";
// 	char	charset1[] = " ,!.";
// 	char	str2[] = "42HeilbronnPiscine";
// 	char	charset2[] = "i";
// 	char	str3[] = "Split;this;string;by;semicolons";
// 	char	charset3[] = ";";
// 	char	str4[] = "NoSeparatorsHere";
// 	char	charset4[] = " ";

// 	result = ft_split(str1, charset1);
// 	if (!result)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("result1[%d]: %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);

// 	result = ft_split(str2, charset2);
// 	if (!result)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("result2[%d]: %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);

// 	result = ft_split(str3, charset3);
// 	if (!result)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("result3[%d]: %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);

// 	result = ft_split(str4, charset4);
// 	if (!result)
// 	{
// 		printf("Memory allocation failed\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		printf("result4[%d]: %s\n", i, result[i]);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);

// 	return (0);
// }