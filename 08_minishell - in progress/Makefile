NAME = minishell

CFLAGS = -Wall -Wextra -Werror

SRCS = 	./src/main.c \
		./src/init/ft_struct_init.c \
		./src/builtins/utils/ft_check_env.c \
		./src/builtins/utils/ft_print_env.c \
		./src/builtins/cd.c \
		./src/builtins/echo.c \
		./src/builtins/env.c

OBJS = $(SRCS:.c=.o)

CC = gcc

LIBFT = ./src/libft/libft.a

INCLUDES = -I ./include -L "/Users/$(USER)/.brew/Cellar/readline/8.2.1/lib" -lreadline

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft $(OBJS) ./include/minishell.h
	$(info Compiling minishell...)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(INCLUDES)
	@echo "\033[0;32mAll done ! Have fun shelling !\033[0m"

all: $(NAME)

libft:
	@make -C src/libft

clean:
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C src/libft
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re