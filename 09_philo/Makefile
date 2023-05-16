NAME = philo

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = 	./src/utils/ft_atoi.c \
		./src/utils/ft_isdigit.c \
		./src/utils/ft_usleep.c \
		./src/utils/is_dead.c \
		./src/utils/print.c \
		./src/utils/timestamp.c \
		./src/init.c \
		./src/main.c \
		./src/philo_state.c

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	gcc -pthread  $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re