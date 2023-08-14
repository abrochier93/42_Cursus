NAME	= cub3D
CFLAGS	= -Wextra -Wall -Werror
LIBMLX	= ./lib/MLX42
HEADERS = ./include/cub3d.h
INCLUDES	= -I ./include -I $(LIBMLX)/include -I lib/libft -I/Users/$(USER)/.brew/opt/libomp/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm ./lib/libft/libft.a


# Sources and objects
MAIN = cub3d
ERROR = ft_msg_err_close ft_msg_err
FREE = free_settings free_game free_map_line free_map
HOOK = hook_base hook_player
INIT = init_cub init_game init_lines_list init_map
LIST = ft_last_lines_list ft_lines_list_add_back ft_lines_list_new ft_list_to_array
MOVES = adjust moves rotate
PARSING = parsing store_map_infos store_map map_is_valid map_correction manage_settings assign_path
FOV = render_fov render_wall texture is_wall draw_wall
COLOR = get_pixels get_rgba load_color manage_colors
UTILS = ft_arraylen ft_deg_to_rad ft_duplicate_map is_playable ft_iswhitespace \
		ft_strtrim get_path get_player_angle get_player_pos \
		is_empty_line is_type_line is_id is_elements_valid ft_file_access \
		ft_char_correction is_multiple_of


SRCS = $(addsuffix .c, $(addprefix src/, $(MAIN))) \
	   $(addsuffix .c, $(addprefix src/error/, $(ERROR))) \
	   $(addsuffix .c, $(addprefix src/free/, $(FREE))) \
	   $(addsuffix .c, $(addprefix src/hook/, $(HOOK))) \
	   $(addsuffix .c, $(addprefix src/init/, $(INIT))) \
	   $(addsuffix .c, $(addprefix src/list/, $(LIST))) \
	   $(addsuffix .c, $(addprefix src/moves/, $(MOVES))) \
	   $(addsuffix .c, $(addprefix src/parsing/, $(PARSING))) \
	   $(addsuffix .c, $(addprefix src/fov/, $(FOV))) \
	   $(addsuffix .c, $(addprefix src/color/, $(COLOR))) \
	   $(addsuffix .c, $(addprefix src/utils/, $(UTILS))) \
	   
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

# valgrind
summary:
	valgrind --leak-check=summary --trace-children=yes --track-fds=yes ./$(NAME) $m

valgrind:
	valgrind --leak-check=full --trace-children=yes --track-fds=yes ./$(NAME) $m

full:
	valgrind --leak-check=full --show-leak-kinds=definite ./$(NAME) $m

leak:
	leaks --atExit -- ./$(NAME) $m
