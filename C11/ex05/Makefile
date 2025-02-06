# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 19:56:15 by fredchar          #+#    #+#              #
#    Updated: 2025/02/02 01:30:00 by fredchar         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRCD := src
INCD := includes
OBJD := obj

NAME := do-op
SRCS := $(SRCD)/ops.c \
		$(SRCD)/ft_do_op.c \
		$(SRCD)/helpers.c \

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