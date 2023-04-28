# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 07:47:09 by abrochie          #+#    #+#              #
#    Updated: 2023/04/27 15:14:59 by abrochie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# https://github.com/vfurmane/pipex-tester
NAME = pipex

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

INC = ./inc/pipex.h \

SRC = ./src/main.c \
	./src/pipex.c \
	./src/pipex_utils.c \
	./src/string_utils.c \
	./src/ft_splitpath.c \
	./src/free.c \

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
