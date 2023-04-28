# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal <digoncal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 11:01:17 by digoncal          #+#    #+#              #
#    Updated: 2023/04/12 15:58:34 by digoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = libs/libft/libft.a

NAME = push_swap

SRC = src/main.c src/free.c src/check_args.c src/operations.c src/quick_sort.c \
	src/sort_algorithm.c src/utils.c
OBJ = $(SRC:.c=.o)

LIBFT = libs/libft/libft.a

all: deps $(NAME)
	
deps:
	$(MAKE) -C ./libs/libft
	
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) $@ -C ./libs/libft
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) $@ -C ./libs/libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./libs/libft
