# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 20:07:34 by fredchar          #+#    #+#              #
#    Updated: 2025/02/05 06:54:03 by fredchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
SRCD := src
INCD := includes
OBJD := obj

NAME := bsq 
SRCS := $(SRCD)/main.c \
		$(SRCD)/helpers.c \
		$(SRCD)/parse_file.c \
		$(SRCD)/file_to_map.c \
		$(SRCD)/init.c \
		$(SRCD)/helpers2.c \
		$(SRCD)/verify_map.c \
		$(SRCD)/solve.c \
		$(SRCD)/solution.c \


OBJS := $(SRCS:$(SRCD)/%.c=$(OBJD)/%.o)

all: $(NAME)

$(OBJD)/%.o: $(SRCD)/%.c | $(OBJD)
	$(CC) $(CFLAGS) -I $(INCD) -c $< -o $@

$(OBJD):
	mkdir -p $(OBJD)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJD)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
