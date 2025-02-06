# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 19:56:15 by fredchar          #+#    #+#              #
#    Updated: 2025/01/30 03:12:44 by fredchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CF = -c -Wall -Wextra -Werror

SRCD = srcs
INCD = includes

NAME = libft.a
SOURCES = $(SRCD)/ft_putchar.c $(SRCD)/ft_swap.c $(SRCD)/ft_putstr.c $(SRCD)/ft_strlen.c $(SRCD)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CF) $< -o $@ -I $(INCD)
	
$(NAME): $(OBJECTS)
	ar cr $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all