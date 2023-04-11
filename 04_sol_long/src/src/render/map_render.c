/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:26:45 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 14:27:18 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_info(t_game *game)
{
	char	*temp;

	game->txt_collect = mlx_new_image(game->mlx, 20, 180);
	game->txt_collect_count = mlx_new_image(game->mlx, 20, 180);
	game->txt_move = mlx_new_image(game->mlx, 20, 180);
	game->txt_move_count = mlx_new_image(game->mlx, 20, 180);
	game->txt_move = mlx_put_string(game->mlx,
			"Player movement: ", 10, game->map_row * 64);
	game->txt_collect = mlx_put_string(game->mlx,
			"Collectible: ", 10, game->map_row * 64 + 20);
	temp = ft_itoa(game->player_move);
	game->txt_collect_count = mlx_put_string(game->mlx,
			temp, 200, game->map_row * 64);
	free(temp);
	temp = ft_itoa(game->map_collectible);
	game->txt_move_count = mlx_put_string(game->mlx,
			temp, 200, game->map_row * 64 + 20);
	free(temp);
}

void	print_player_move(t_game *game)
{
	game->player_move++;
	can_exit(game);
	game->next_move = mlx_get_time() + 0.35;
	if (game->player_move == 0)
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