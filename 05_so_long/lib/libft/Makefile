# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 11:57:09 by abrochie          #+#    #+#              #
#    Updated: 2023/04/06 14:00:37 by abrochie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCE = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_memmove.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
		 	ft_putendl_fd.c \
			ft_substr.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_strmapi.c \
			ft_strlcat.c \
			ft_strjoin.c \
			ft_striteri.c \
			ft_split.c \
			get_next_line_utils.c \
			get_next_line.c \

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

HEADER = libft.h
OBJSB = $(BONUS:.c=.o)
OBJS = $(SOURCE:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJSB)
	ar rc $(NAME) $(OBJSB)
	ranlib $(NAME)
	
	
clean:
	rm -f $(OBJS)
	rm -f $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus