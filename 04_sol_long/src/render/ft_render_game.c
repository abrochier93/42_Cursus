/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:25:08 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 15:05:12 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_texture(t_file *game)
{
	game->player_texture = mlx_load_png("assets/mushroom.png");
	// game->mushroom_texture = mlx_load_png("");
	// game->wall_texture = mlx_load_png("");
	// game->house_texture = mlx_load_png("");
	// game->floor_texture = mlx_load_png("assets/floor");
}

static void	set_player_exit(t_file *game)
{
	game->player_image = mlx_new_image(game->mlx, 64, 64);
	//game->house_image = mlx_new_image(game->mlx, 64, 64);
	game->player_image = mlx_texture_to_image(game->mlx, game->player_texture);
	//game->house_image = mlx_texture_to_image(game->mlx, game->house_texture);
}

// static void	set_floors_walls(t_file *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->n_floor)
// 	{
// 		game->floor_image[i] = mlx_new_image(game->mlx, 64, 64);
// 		game->floor_image[i] = mlx_texture_to_image(game->mlx, game->floor_texture);
// 		mlx_image_to_window(game->mlx, game->floor[i],
// 			game->floor_col[i] * 64, game->floor_row[i] * 64);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < game->map_wall)
// 	{
// 		game->wall[i] = mlx_new_image(game->mlx, 64, 64);
// 		game->wall[i] = mlx_texture_to_image(game->mlx, game->wall_texture);
// 		mlx_image_to_window(game->mlx, game->wall[i],
// 			game->wall_col[i] * 64, game->wall_row[i] * 64);
// 		i++;
// 	}
// }

// static void	set_collectibles(t_file *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->map_collectible)
// 	{
// 		game->collect[i] = mlx_new_image(game->mlx, 64, 64);
// 		game->collect[i] = mlx_texture_to_image(game->mlx, game->db);
// 		mlx_image_to_window(game->mlx, game->collect[i],
// 			game->collect_col[i] * 64, game->collect_row[i] * 64);
// 		i++;
// 	}
// }

int	ft_render_game(t_file *game)
{
	set_texture(game);
	game->mlx = mlx_init(64 * game->n_cols,
			64 * (game->n_rows + 1), "MLX42", true);
	//print_player_move(game);
	mlx_set_window_title(game->mlx, "So Long - blue mushroom");
	if (!game->mlx)
		exit(EXIT_FAILURE);
	set_player_exit(game);
	//set_floors_walls(game);
	//set_collectibles(game);
	mlx_image_to_window(game->mlx, game->player_image,
		(game->player_pos.x) * 64, (game->player_pos.y) * 64);
	// mlx_image_to_window(game->mlx, game->door,
	// 	(game->exit_col) * 64, (game->exit_row) * 64);
	// mlx_loop_hook(game->mlx, &hook, (void *)game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	//free_game(game, 1);
	return (EXIT_SUCCESS);
}