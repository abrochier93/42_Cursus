/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_validation_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:31:01 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 14:31:11 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delete_db_image(t_game	*game)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->collect[i])
	{
		if (game->collect_col[i] != game->player_col
			|| game->collect_row[i] != game->player_row)
			count++;
		else
		{
			mlx_delete_image(game->mlx, game->collect[count]);
			break ;
		}
		i++;
	}
}

static int	check_if_collect_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_row)
	{
		j = 0;
		while (j < game->map_col)
		{
			if (game->value_map[i][j] > 0)
			{
				if (game->maps[i][j] == 'C' || game->maps[i][j] == 'C')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	player_can_finish(t_game *game)
{
	set_direction(game);
	check_all_direction(game, game->player_row, game->player_col);
	if (check_if_collect_left(game) != 0)
		return (1);
	return (0);
}

void	collect_item(t_game *game, int dir)
{
	if (dir == 0)
		game->player_row--;
	else if (dir == 1)
		game->player_row++;
	else if (dir == 2)
		game->player_col--;
	else if (dir == 3)
		game->player_col++;
	if (game->maps[game->player_row][game->player_col] == 'C')
	{
		game->map_collectible--;
		game->maps[game->player_row][game->player_col] = '0';
		delete_db_image(game);
	}
	print_player_move(game);
}

void	can_exit(t_game *game)
{
	mlx_image_t	*temp_image_1;
	mlx_image_t	*temp_image_2;

	if (game->map_collectible == 0
		&& game->maps[game->player_row][game->player_col] == 'E')
	{
		temp_image_1 = mlx_put_string(game->mlx,
				"You Won!", 10, game->map_row * 64 + 40);
		game->game_finish = 1;
		temp_image_2 = mlx_put_string(game->mlx,
				" Close to restart!", 85, game->map_row * 64 + 40);
	}
}
