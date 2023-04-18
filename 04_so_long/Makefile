# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 10:15:47 by abrochie          #+#    #+#              #
#    Updated: 2023/04/18 10:26:05 by abrochie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror
LIBMLX	= ./lib/MLX42
HEADERS = ./include/so_long.h
INCLUDES	= -I ./include -I $(LIBMLX)/include -I lib/libft -I/Users/$(USER)/.brew/opt/libomp/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm ./lib/libft/libft.a

SRCS	= 	src/msg_error/ft_file_missing.c \
			src/msg_error/ft_foreign_char.c \
			src/msg_error/ft_is_not_ber.c \
			src/msg_error/ft_is_not_close.c \
			src/msg_error/ft_is_not_rectangle.c \
			src/msg_error/ft_map_to_big.c \
			src/msg_error/ft_no_collectible.c \
			src/msg_error/ft_no_exit.c \
			src/msg_error/ft_no_path.c \
			src/msg_error/ft_player_error.c \
			src/msg_error/ft_to_many_file.c \
			src/ft_check_file.c \
			src/ft_check_path.c \
			src/ft_init_map.c \
			src/ft_validate_map.c \
			src/render/ft_render_game.c \
			src/render/ft_render_game_utils.c \
			src/render/ft_hook.c \
			src/render/ft_make_move.c \
			src/main.c \
					
OBJS	= ${SRCS:.c=.o}

all: libft libmlx $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME) $(INCLUDES)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && cmake --build $(LIBMLX)/build -j4

libft:
	$(info Compiling libft...)
	@make -C lib/libft

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES) && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -f $(OBJS)
	$(info Cleaning MLX42...)
	@rm -rf $(LIBMLX)/build
	@make clean -C lib/libft
	$(info Done!)

fclean: clean
	$(info Cleaning...)
	@rm -f $(NAME)
	@make fclean -C lib/libft
	$(info Done!)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx