/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:25:08 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/11 16:02:08 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	set_textures(t_file *game)
{
	game->player_texture = mlx_load_png("assets/player.png");
	game->collectibe_texture = mlx_load_png("assets/collectible.png");
	game->wall_texture = mlx_load_png("assets/wall.png");
	game->exit_texture = mlx_load_png("assets/exit.png");
	game->floor_texture = mlx_load_png("assets/floor.png");
}

static void	set_images(t_file *game)
{
	game->player_image = mlx_new_image(game->mlx, 64, 64);
	game->collectible_image =mlx_new_image(game->mlx, 64, 64);
	game->wall_image = mlx_new_image(game->mlx, 64, 64);
	game->exit_image = mlx_new_image(game->mlx, 64, 64);
	game->floor_image = mlx_new_image(game->mlx, 64, 64);
	game->player_image = mlx_texture_to_image(game->mlx, game->player_texture);
	game->collectible_image = mlx_texture_to_image(game->mlx, game->collectibe_texture);
	game->wall_image = mlx_texture_to_image(game->mlx, game->wall_texture);
	game->exit_image = mlx_texture_to_image(game->mlx, game->exit_texture);
	game->floor_image = mlx_texture_to_image(game->mlx, game->floor_texture);
}

static void set_map(t_file *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->n_rows)
	{
		x = 0;
		while (x < map->n_cols)
		{
			if (map->map[y][x] == '1')
				mlx_image_to_window(map->mlx, map->wall_image, x * 64, y * 64);
			if (map->map[y][x] == 'C')
				mlx_image_to_window(map->mlx, map->collectible_image, x * 64, y * 64);
			if (map->map[y][x] == 'P')
				mlx_image_to_window(map->mlx, map->player_image, x * 64, y * 64);
			if (map->map[y][x] == 'E')
				mlx_image_to_window(map->mlx, map->exit_image, x * 64, y * 64);
			if (map->map[y][x] == '0')
				mlx_image_to_window(map->mlx, map->floor_image, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

static void free_game(t_file *game)
{
		free(game->player_texture);
		free(game->wall_texture);
		free(game->exit_texture);
		free(game->floor_texture);
		free(game->collectibe_texture);

}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		image->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		image->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		image->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		image->instances[0].x += 64;
}

int	ft_render_game(t_file *game)
{
	int next_move;
	set_textures(game);
	game->mlx = mlx_init(64 * game->n_cols,
			64 * (game->n_rows), "MLX42", true);
	//print_player_move(game);
	mlx_set_window_title(game->mlx, "So Long");
	if (!game->mlx)
		exit(EXIT_FAILURE);
	set_images(game);
	set_map(game);
	image = game->player_image;
	next_move = mlx_get_time() + 0.35;
	mlx_loop_hook(game->mlx, ft_hook, game->mlx);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}