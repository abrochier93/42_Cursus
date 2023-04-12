static void	delete_textures(t_file *game)
{
	if (game->player_texture)
		mlx_delete_texture(game->player_texture);
	if (game->collectibe_texture)
		mlx_delete_texture(game->collectibe_texture);
	if (game->wall_texture)
		mlx_delete_texture(game->wall_texture);
	if (game->exit_texture)
		mlx_delete_texture(game->exit_texture);
	if (game->floor_texture)
		mlx_delete_texture(game->floor_texture);
}

static void	set_player_info(t_game *game)
{
	char	*temp;

	game->txt_collect = mlx_new_image(game->mlx, 20, 180);
	game->txt_collect_count = mlx_new_image(game->mlx, 20, 180);
	game->txt_move = mlx_new_image(game->mlx, 20, 180);
	game->txt_move_count = mlx_new_image(game->mlx, 20, 180);
	game->txt_move = mlx_put_string(game->mlx, "Player movement: ", 10, game->map_row * 64);
	game->txt_collect = mlx_put_string(game->mlx, "Collectible: ", 10, game->map_row * 64 + 20);
	temp = ft_itoa(game->n_move);
	game->txt_collect_count = mlx_put_string(game->mlx, temp, 200, game->map_row * 64);
	free(temp);
	temp = ft_itoa(game->map_collectible);
	game->txt_move_count = mlx_put_string(game->mlx, temp, 200, game->map_row * 64 + 20);
	free(temp);
}

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

void	print_player_move(t_game *game)
{
	game->n_move++;
	ft_is_exit(game);
	game->next_move = mlx_get_time() + 0.35;
	if (game->n_move == 0)
	{
		set_player_info(game);
	}
	else
	{
		mlx_delete_image(game->mlx, game->txt_collect);
		mlx_delete_image(game->mlx, game->txt_collect_count);
		mlx_delete_image(game->mlx, game->txt_move);
		mlx_delete_image(game->mlx, game->txt_move_count);
		set_player_info(game);
	}
}