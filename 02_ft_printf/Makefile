CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCE = ft_printf_utils.c \
			ft_printf.c \
			


HEADER = ft_printf.h
OBJS = $(SOURCE:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)	
	
clean:
	rm -f $(OBJS)
	rm -f $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all 