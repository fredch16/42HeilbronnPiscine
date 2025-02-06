/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:24:58 by swied             #+#    #+#             */
/*   Updated: 2025/02/05 20:42:51 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024
# define BUFFER_STDIN 10000000000 

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
}	t_map;

typedef struct s_sq
{
	int	x;
	int	y;
	int	len;
}	t_sq;

typedef struct s_data
{
	t_map	*map;
	t_sq	*bsq;
}	t_data;

void	print_map(t_map *map);

// helpers.c

void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dst, char *src, unsigned int n);
char	*ft_strdup(char *str);

// helpers2.c

int		is_printable(char c);
int		is_num(char c);
int		is_alpha(char c);
void	*ft_memset(void *b, int c, size_t len);
char	*read_stdin(void);

// init.c

void	init_data(t_data *data);
void	free_map(t_map *map);
void	init_sq(t_sq *sq);

// parse_map.c

t_map	*get_map(char *map_path, int argc);

// file_to_map.c

t_map	*content_to_map(char *content);
char	**create_map(t_map *map);
void	fill_map(char *str, t_map *map);

// verify_map.c

int		verify_map(char *content, t_map *map);

// solve.c

int		solve(t_data *data);

// solution.c

char	**put_solution(t_map *map, t_sq *sq);

#endif