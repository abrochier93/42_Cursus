void	ft_is_exit(t_game *game)
{
	mlx_image_t	*temp_image_1;
	mlx_image_t	*temp_image_2;

	if (game->map_collectible == 0
		&& game->maps[game->player_row][game->player_col] == 'E')
	{
		temp_image_1 = mlx_put_string(game->mlx, "You Won!", 10, game->map_row * 64 + 40);
		temp_image_2 = mlx_put_string(game->mlx, " Close to restart!", 85, game->map_row * 64 + 40);
		game->game_finish = 1;
	}
}


/*       CODE A TESTER      */

int	ft_render_game(t_file *game)
{
	mlx_loop_hook(game->mlx, &hook, (void *)game);
	return (EXIT_SUCCESS);
}

void	hook(void *params)
{
	t_game	*game;

	game = params;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && can_move_up(game))
		ft_make_move(game->map[game->player_row - 1][game->player_col], game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && can_move_down(game))
		ft_make_move(game->map[game->player_row + 1][game->player_col], game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A) && can_move_left(game))
		ft_make_move(game->map[game->player_row][game->player_col - 1], game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && can_move_right(game))
		ft_make_move(game->map[game->player_row][game->player_col + 1], game);
}

static int	can_move_up(t_game *game)
{
	if ((game->maps[game->player_row - 1][game->player_col] == '0'
		|| game->maps[game->player_row - 1][game->player_col] == 'C'
		|| game->maps[game->player_row - 1][game->player_col] == 'P'
		|| game->maps[game->player_row - 1][game->player_col] == 'E')
		&& mlx_get_time() > game->next_move && game->game_finish != 1)
	{
		return (1);
	}
	return (0);
}

static int	can_move_down(t_game *game)
{
	if ((game->maps[game->player_row + 1][game->player_col] == '0'
		|| game->maps[game->player_row + 1][game->player_col] == 'C'
		|| game->maps[game->player_row + 1][game->player_col] == 'E'
		|| game->maps[game->player_row + 1][game->player_col] == 'P')
		&& mlx_get_time() > game->next_move && game->game_finish != 1)
	{
		return (1);
	}
	return (0);
}

static int	can_move_left(t_game *game)
{
	if ((game->maps[game->player_row][game->player_col - 1] == '0'
		|| game->maps[game->player_row][game->player_col - 1] == 'C'
		|| game->maps[game->player_row][game->player_col - 1] == 'P'
		|| game->maps[game->player_row][game->player_col - 1] == 'E')
		&& mlx_get_time() > game->next_move && game->game_finish != 1)
	{
		return (1);
	}
	return (0);
}

static int	can_move_right(t_game *game)
{
	if ((game->maps[game->player_row][game->player_col + 1] == '0'
		|| game->maps[game->player_row][game->player_col + 1] == 'C'
		|| game->maps[game->player_row][game->player_col + 1] == 'E'
		|| game->maps[game->player_row][game->player_col + 1] == 'P')
		&& mlx_get_time() > game->next_move && game->game_finish != 1)
	{
		return (1);
	}
	return (0);
}

void	ft_swap_tiles(char *tile1, char *tile2)
{
	char	temp;

	temp = *tile1;
	*tile1 = *tile2;
	*tile2 = temp;
}

void	ft_is_E(char *exit, t_file *game)
{
	if (exit == 'E' && game->collectible_found == game->n_collectible)
	{
		*exit = '0';
		game->game_finish = 1;
	}
	if (exit == 'E' && game->collectible_found != game->n_collectible)
	{
		ft_putstr("ramassez d'abord tous les collectibles");
	}	
}

void	ft_is_C(char *collect, t_file *game)
{
	if (collect == 'C')
	{
		*collect = '0';
		game->collectible_found++;
	}
}

void 	ft_make_move(char *movement, t_file *game)
{
	ft_is_C(movement, game);
	ft_is_E(movement, game);
	ft_swap_tiles(game->map[game->player_row][game->player_col], movement);
	//set la map;
}
