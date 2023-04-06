void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	ft_swap_tiles(char *tile1, char *tile2)
{
	char	temp;

	temp = *tile1;
	*tile1 = *tile2;
	*tile2 = temp;
}

void	ft_remove_collect(char *player, char *collect)
{
	*collect = *player;
	*player = '0';
}

void	ft_found_exit(char *player, char *collect)
{
	*collect = *player;
	*player = '0';
}

void	ft_check_if_end(t_map *map)
{
	long	i;

	i = 0;
	if (map->end_game == 1 || map->p_death == 1)
	{
		while (i != 222222222)
			i++;
		ft_end_game(map);
		exit(0);
	}
}

void	ft_print_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		ft_put_str(map[y]);
		y++;
	}
}

void	ft_end_game(t_map *map)
{
	ft_put_str("So long, child...\n");
	mlx_destroy_window(map->mlx, map->win);
	free(map->map);
	exit(0);
}

void	ft_moved_into_collect(t_map *map, int x, int y)
{
	int	p_y;
	int	p_x;

	p_x = map->p_x;
	p_y = map->p_y;
	ft_remove_collect(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
	ft_put_str("You collected an object!\n");
	map->n_collect -= 1;
	map->found_collect = 1;
}

void	ft_moved_into_exit(t_map *map, int x, int y)
{
	int	p_y;
	int	p_x;

	p_y = map->p_y;
	p_x = map->p_x;
	if (map->n_collect == 0)
	{
		ft_found_exit(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
		map->end_game = 1;
		ft_put_str("You found an exit!\n");
		ft_put_str("Press any key to exit.\n");
	}
	else
		ft_put_str("Collect all objects first.\n");
}

void	ft_move_player(t_map *map, int x, int y)
{
	int	p_y;
	int	p_x;

	p_y = map->p_y;
	p_x = map->p_x;
	map->found_collect = 0;
	ft_check_if_end(map);
	if (map->map[p_y + y][p_x + x] != '1')
	{
		map->moves += 1;
		if (map->map[p_y + y][p_x + x] == '0')
			ft_swap_tiles(&map->map[p_y][p_x], &map->map[p_y + y][p_x + x]);
		else if (map->map[p_y + y][p_x + x] == 'C')
			ft_moved_into_collect(map, x, y);
		else if (map->map[p_y + y][p_x + x] == 'E')
			ft_moved_into_exit(map, x, y);
	}
	ft_populate_map(map, 40, 0);
	ft_put_str("Moves: ");
	ft_putnbr_fd(map->moves, 1);
	ft_put_str("\n");
}

int	ft_close_window(t_map *map)
{
	ft_end_game(map);
	return (1);
}

int	ft_key_event(t_map *map, int py, int px, int direction)
{
	ft_move_player(map, py, px);
	map->p_direction = direction;
	ft_populate_map(map, 40, 0);
	return (1);
}

int	ft_keyboard_events(int key, t_map *map)
{
	if (key == 65307 || key == 53)
		ft_close_window(map);
	if (map->p_death != 1 && map->end_game != 1)
	{
		if (key == 119 || key == 65362 || key == 13 || key == 126)
			ft_key_event(map, 0, -1, 0);
		else if (key == 100 || key == 65363 || key == 2 || key == 124)
			ft_key_event(map, 1, 0, 1);
		else if (key == 115 || key == 65364 || key == 1 || key == 125)
			ft_key_event(map, 0, 1, 2);
		else if (key == 97 || key == 65361 || key == 0 || key == 123)
			ft_key_event(map, -1, 0, 3);
	}
	else
		ft_close_window(map);
	return (1);
}

void	ft_listen_events(t_map *map)
{
	mlx_hook(map->win, 02, (1L << 0), ft_keyboard_events, map);
	mlx_hook(map->win, 17, (1L << 8), ft_close_window, map);
}

void	ft_render_rocks(t_map *map, int offset, int index)
{
	if ((index + 1) % 5 == 0)
		ft_render_tile(map, "./img/rock_3.xpm", offset);
	else if ((index + 1) % 3 == 0)
		ft_render_tile(map, "./img/rock_2.xpm", offset);
	else
		ft_render_tile(map, "./img/rock_1.xpm", offset);
}

void	ft_render_player(t_map *map, int offset, int x, int y)
{
	if (map->end_game == 1)
		ft_render_tile(map, "./img/success.xpm", offset);
	else if (map->p_death == 1)
		ft_render_tile(map, "./img/dead.xpm", offset);
	else if (map->found_collect == 1)
	{
		if (map->x % 2 == 0)
			ft_render_tile(map, "./img/yoda_egg.xpm", offset);
		else if (map->x % 2 != 0)
			ft_render_tile(map, "./img/yoda_star.xpm", offset);
	}
	else
	{	
		if (map->p_direction == 0)
			ft_render_tile(map, "./img/player_up.xpm", offset);
		else if (map->p_direction == 1)
			ft_render_tile(map, "./img/player_right.xpm", offset);
		else if (map->p_direction == 2)
			ft_render_tile(map, "./img/player.xpm", offset);
		else if (map->p_direction == 3)
			ft_render_tile(map, "./img/player_left.xpm", offset);
	}
	map->p_x = x;
	map->p_y = y;
}

void	ft_render_exit(t_map *map, int offset, int start)
{
	if (start == 0 && map->n_collect == 0)
		ft_render_tile(map, "./img/exit.xpm", offset);
	else
		ft_render_tile(map, "./img/exit_closed.xpm", offset);
}

void	ft_render_collectible(t_map *map, int offset, int start)
{
	if (start == 1)
		map->n_collect += 1;
	if (map->x % 2 == 0)
		ft_render_tile(map, "./img/egg_1.xpm", offset);
	else if (map->x % 2 != 0)
		ft_render_tile(map, "./img/star.xpm", offset);
}

void	ft_render_tile(t_map *map, char *path, int off)
{
	t_img		tile;
	static void	*r_tile;
	static char	*previous_path;
	int			i_x;
	int			i_y;

	tile.w = 32;
	tile.h = 32;
	i_x = map->x * 32 + off;
	i_y = map->y * 32 + off;
	if (!previous_path)
		previous_path = ft_strdup(path);
	if (!r_tile || ft_compare_strings(previous_path, path) == 0)
		r_tile = mlx_xpm_file_to_image(map->mlx, path, &tile.w, &tile.h);
	mlx_put_image_to_window(map->mlx, map->win, r_tile, i_x, i_y);
	free(previous_path);
	previous_path = ft_strdup(path);
}

void	ft_populate_map(t_map *map, int offset, int start)
{
	map->x = 0;
	map->y = 0;
	while (map->map[map->y][0] != '\n')
	{
		map->x = 0;
		while (map->map[map->y][map->x] != '\0')
		{
			if (map->map[map->y][map->x] == '0')
				ft_render_tile(map, "./img/water.xpm", offset);
			else if (map->map[map->y][map->x] == '1')
				ft_render_rocks(map, offset, map->y + map->x);
			else if (map->map[map->y][map->x] == 'P')
				ft_render_player(map, offset, map->x, map->y);
			else if (map->map[map->y][map->x] == 'E')
				ft_render_exit(map, offset, start);
			else if (map->map[map->y][map->x] == 'C')
				ft_render_collectible(map, offset, start);
			map->x += 1;
		}
		map->y += 1;
	}
}

void	ft_initialize_stats(t_map *map)
{
	map->end_game = 0;
	map->moves = 0;
	map->n_collect = 0;
	map->enem_n = 0;
	map->p_death = 0;
	map->p_direction = 2;
}

void	ft_welcome_player(void)
{
	ft_put_str("Hello, child! Welcome to 42 Escape.\n");
	ft_put_str("Your goal is escaping in the smallest number of moves.\n");
	ft_put_str("Don't forget to collect all the objects, though...\n");
}

void	ft_render_map(t_map *map)
{
	int	offset;
	int	screen_w;
	int	screen_h;

	offset = 40;
	screen_w = map->n_cols * 32 + offset * 2;
	screen_h = map->n_rows * 32 + offset * 2;
	if (screen_w > 2048 || screen_h > 1080)
	{
		ft_put_str("Error\n");
		ft_put_str("Map is too big.\n");
		exit(0);
	}
	else
	{
		ft_welcome_player();
		map->mlx = mlx_init();
		map->win = mlx_new_window(map->mlx, screen_w, screen_h, "42 Escape");
		ft_initialize_stats(map);
		ft_populate_map(map, offset, 1);
		ft_listen_events(map);
		mlx_loop(map->mlx);
	}
}

//utils
static int	ft_cal_number_digits(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while ((unsigned int)n > 0)
	{
		res++;
		n = (unsigned int)n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num_digits;

	num_digits = ft_cal_number_digits(n);
	res = malloc((num_digits + 1) * sizeof(char));
	if (n == 0)
		res[0] = 48;
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[num_digits] = '\0';
	while ((num_digits - 1) >= 0 && (unsigned int)n > 0)
	{	
		res[num_digits - 1] = ((unsigned int)n % 10) + '0';
		n = (unsigned int)n / 10;
		num_digits--;
	}
	return (res);
}

int	ft_compare_strings(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_moves(t_map *map)
{		
	ft_put_str("Moves: ");
	ft_putnbr_fd(map->moves, 1);
	ft_put_str("\n");
}
