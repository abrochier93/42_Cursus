/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:17:07 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/13 16:07:16 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap_tiles(char *tile1, char *tile2)
{
	char	temp;

	temp = *tile1;
	*tile1 = *tile2;
	*tile2 = temp;
}

void	ft_is_e(char *letter, t_file *game)
{
	char	exit;

	exit = *letter;
	if (exit == 'E' && game->found_collect == game->n_collect)
	{
		*letter = '0';
		game->game_is_finish = 1;
	}
	if (exit == 'E' && game->found_collect != game->n_collect)
	{
		ft_putstr_fd("Collect First The Dofus\n", 1);
		ft_loop_game(game);
	}
}

void	ft_is_c(char *letter, t_file *game)
{
	char	collect;

	collect = *letter;
	if (collect == 'C')
	{
		*letter = '0';
		game->found_collect++;
	}
}

void	ft_update_player_position(t_file *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->n_rows)
	{
		x = 0;
		while (x < map->n_cols)
		{
			if (map->map[y][x] == 'P')
			{
				map->p_pos.x = x;
				map->p_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_make_move(char *movement, t_file *game)
{
	ft_is_e(movement, game);
	game->n_moves++;
	ft_is_c(movement, game);
	ft_swap_tiles(&game->map[game->p_pos.y][game->p_pos.x], movement);
	ft_update_player_position(game);
	ft_loop_game(game);
}
