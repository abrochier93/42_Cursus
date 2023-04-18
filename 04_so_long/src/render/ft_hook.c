/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:07:35 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/13 06:10:23 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move_up(t_file *game)
{
	if ((game->map[game->p_pos.y - 1][game->p_pos.x] == '0'
		|| game->map[game->p_pos.y - 1][game->p_pos.x] == 'C'
		|| game->map[game->p_pos.y - 1][game->p_pos.x] == 'P'
		|| game->map[game->p_pos.y - 1][game->p_pos.x] == 'E')
		&& mlx_get_time() > game->time_next_move && game->game_is_finish != 1)
	{
		return (1);
	}
	return (0);
}

static int	can_move_down(t_file *game)
{
	if ((game->map[game->p_pos.y + 1][game->p_pos.x] == '0'
		|| game->map[game->p_pos.y + 1][game->p_pos.x] == 'C'
		|| game->map[game->p_pos.y + 1][game->p_pos.x] == 'E'
		|| game->map[game->p_pos.y + 1][game->p_pos.x] == 'P')
		&& mlx_get_time() > game->time_next_move && game->game_is_finish != 1)
	{
		return (1);
	}
	return (0);
}

static int	can_move_left(t_file *game)
{
	if ((game->map[game->p_pos.y][game->p_pos.x - 1] == '0'
		|| game->map[game->p_pos.y][game->p_pos.x - 1] == 'C'
		|| game->map[game->p_pos.y][game->p_pos.x - 1] == 'P'
		|| game->map[game->p_pos.y][game->p_pos.x - 1] == 'E')
		&& mlx_get_time() > game->time_next_move && game->game_is_finish != 1)
	{
		return (1);
	}
	return (0);
}

static int	can_move_right(t_file *game)
{
	if ((game->map[game->p_pos.y][game->p_pos.x + 1] == '0'
		|| game->map[game->p_pos.y][game->p_pos.x + 1] == 'C'
		|| game->map[game->p_pos.y][game->p_pos.x + 1] == 'E'
		|| game->map[game->p_pos.y][game->p_pos.x + 1] == 'P')
		&& mlx_get_time() > game->time_next_move && game->game_is_finish != 1)
	{
		return (1);
	}
	return (0);
}

void	hook(void *params)
{
	t_file	*game;

	game = params;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && can_move_up(game))
		ft_make_move(&game->map[game->p_pos.y - 1][game->p_pos.x], game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && can_move_down(game))
		ft_make_move(&game->map[game->p_pos.y + 1][game->p_pos.x], game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A) && can_move_left(game))
		ft_make_move(&game->map[game->p_pos.y][game->p_pos.x - 1], game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && can_move_right(game))
		ft_make_move(&game->map[game->p_pos.y][game->p_pos.x + 1], game);
}
