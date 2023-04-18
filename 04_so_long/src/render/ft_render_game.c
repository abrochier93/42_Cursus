/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:25:08 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/13 16:11:35 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_textures(t_file *game)
{
	game->player_texture = mlx_load_png("assets/player.png");
	game->collect_text = mlx_load_png("assets/collectible.png");
	game->wall_texture = mlx_load_png("assets/wall.png");
	game->exit_texture = mlx_load_png("assets/exit.png");
	game->floor_texture = mlx_load_png("assets/floor.png");
}

static void	set_images(t_file *game)
{
	game->player_img = mlx_new_image(game->mlx, 64, 64);
	game->collect_img = mlx_new_image(game->mlx, 64, 64);
	game->wall_img = mlx_new_image(game->mlx, 64, 64);
	game->exit_img = mlx_new_image(game->mlx, 64, 64);
	game->floor_img = mlx_new_image(game->mlx, 64, 64);
	game->player_img = mlx_texture_to_image(game->mlx, game->player_texture);
	game->collect_img = mlx_texture_to_image(game->mlx, game->collect_text);
	game->wall_img = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->exit_img = mlx_texture_to_image(game->mlx, game->exit_texture);
	game->floor_img = mlx_texture_to_image(game->mlx, game->floor_texture);
}

static void	set_map(t_file *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->n_rows)
	{
		x = 0;
		while (x < map->n_cols)
		{
			if (map->map[y][x] == '1')
				mlx_image_to_window(map->mlx, map->wall_img, x * 64, y * 64);
			if (map->map[y][x] == 'C')
				mlx_image_to_window(map->mlx, map->collect_img, x * 64, y * 64);
			if (map->map[y][x] == 'P')
				mlx_image_to_window(map->mlx, map->player_img, x * 64, y * 64);
			if (map->map[y][x] == 'E')
				mlx_image_to_window(map->mlx, map->exit_img, x * 64, y * 64);
			if (map->map[y][x] == '0')
				mlx_image_to_window(map->mlx, map->floor_img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_loop_game(t_file *game)
{
	print_game_info(game);
	set_map(game);
	game->time_next_move = mlx_get_time() + 0.4;
	mlx_loop_hook(game->mlx, &hook, (void *)game);
	mlx_loop(game->mlx);
}

int	ft_render_game(t_file *game)
{
	game->mlx = mlx_init(64 * game->n_cols,
			64 * (game->n_rows), "MLX42", true);
	mlx_set_window_title(game->mlx, "So Long");
	if (!game->mlx)
		exit(EXIT_FAILURE);
	set_player_move(game);
	set_textures(game);
	set_images(game);
	ft_loop_game(game);
	mlx_terminate(game->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}
