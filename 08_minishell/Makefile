NAME = minishell

CFLAGS = -Wall -Wextra -Werror

SRCS = 	./main.c\
		./src/setup_shell.c \
		./src/config_signals.c \
		./src/utils/valid_input.c \
		./src/utils/streq.c \
		./src/utils/error.c \
		./src/utils/is_onstr.c \
		./src/utils/join_free.c \
		./src/utils/is_spaces.c \
		./src/utils/is_all_digits_or_signals.c \
		./src/utils/init_envp_lst.c \
		./src/utils/free_matrix.c \
		./src/utils/destroy.c \
		./src/utils/linked_lists/v_llst_utils.c \
		./src/utils/linked_lists/v_llst_utils_v2.c \
		./src/utils/linked_lists/p_llst_utils.c \
		./src/parser/remove_quotes.c \
		./src/parser/parser.c \
		./src/parser/parser_utils.c \
		./src/parser/invalid_syntax.c \
		./src/formater/formater.c\
		./src/formater/formater_utils.c \
		./src/executes/redirects.c \
		./src/executes/pipe.c \
		./src/executes/executables.c \
		./src/executes/exec_cmd.c \
		./src/commands/builtins.c \
		./src/commands/binaries.c \
		./src/commands/builtins/unset.c \
		./src/commands/builtins/pwd.c \
		./src/commands/builtins/export.c \
		./src/commands/builtins/exit.c \
		./src/commands/builtins/env.c \
		./src/commands/builtins/echo.c \
		./src/commands/builtins/cd.c \
		./src/commands/builtins/utils/cd_to_many_args.c \
		./src/commands/builtins/utils/cmd_not_found.c \
		./src/commands/builtins/utils/is_absolute_path.c \

OBJS = $(SRCS:.c=.o)

CC = gcc -g

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

leak:		
	@rm -f report.txt
	@exec 3<>report.txt;valgrind --suppressions=ignore_rdl_leaks.txt --partial-loads-ok=yes --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --log-fd=3 ./minishell

.PHONY: all clean fclean re