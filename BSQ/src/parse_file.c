/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:40:04 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/05 07:46:41 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

char	*append_buffer(char *content, char *buffer, int tb, int bread)
{
	char	*new_content;

	new_content = (char *)malloc(sizeof(char) * (tb + bread + 1));
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	ft_strncpy(new_content, content, tb);
	ft_strncpy(new_content + tb, buffer, bread);
	new_content[tb + bread] = '\0';
	free(content);
	return (new_content);
}

char	*read_file_content(int fd)
{
	int		bytes_read;
	char	*content;
	int		total_bytes;
	char	buffer[BUFFER_SIZE];

	content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!content)
		return (NULL);
	total_bytes = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		content = append_buffer(content, buffer, total_bytes, bytes_read);
		if (!content)
			return (NULL);
		total_bytes += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	content[total_bytes] = '\0';
	return (content);
}

t_map	*read_map(int fd)
{
	char	*content;
	t_map	*map;

	content = read_file_content(fd);
	if (!content)
		return (NULL);
	map = content_to_map(content);
	free(content);
	return (map);
}

t_map	*stdin_to_map(void)
{
	t_map	*map;
	char	*stdin_content;

	stdin_content = read_stdin();
	if (!stdin_content)
		return (NULL);
	map = content_to_map(stdin_content);
	free(stdin_content);
	if (!map)
		return (NULL);
	return (map);
}

t_map	*get_map(char *map_path, int argc)
{
	int		map_fd;
	t_map	*map;

	if (argc == 1)
		return (stdin_to_map());
	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
	{
		ft_putstr_fd("map error\n", 2);
		return (NULL);
	}
	map = read_map(map_fd);
	close(map_fd);
	if (!map)
		return (NULL);
	return (map);
}
