/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:22:30 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 14:24:33 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delete_textures(t_file *game)
{
	if (game->db)
		mlx_delete_texture(game->db);
	if (game->perso)
		mlx_delete_texture(game->perso);
	if (game->shenron)
		mlx_delete_texture(game->shenron);
	if (game->wall_texture)
		mlx_delete_texture(game->wall_texture);
	if (game->floor_texture)
		mlx_delete_texture(game->floor_texture);
}

static void	free_arrays(t_file *game)
{
	free(game->collect_col);
	free(game->collect_row);
	free(game->collect);
	if (game->game_state > 1)
	{
		free(game->wall_col);
		free(game->wall_row);
		free(game->wall);
	}
	if (game->game_state > 2)
	{
		free(game->floor_col);
		free(game->floor_row);
		free(game->floor);
	}
}

static void	free_maps(t_file *game)
{
	int	i;

	i = 0;
	while (game->value_map[i])
	{
		free (game->value_map[i]);
		i++;
	}
	free (game->value_map);
	i = 0;
	while (game->maps[i])
	{
		free (game->maps[i]);
		i++;
	}
	free (game->maps);
}

void	free_game(t_file *game, int isRender)
{
	if (isRender != 0)
		delete_textures(game);
	if (game->game_state > 0)
		free_arrays(game);
	if (game->game_state > 3)
		free_maps(game);
}