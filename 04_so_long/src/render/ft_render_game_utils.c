/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:12:55 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/13 16:12:57 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_file *game)
{
	if (game->player_texture)
		mlx_delete_texture(game->player_texture);
	if (game->collect_text)
		mlx_delete_texture(game->collect_text);
	if (game->wall_texture)
		mlx_delete_texture(game->wall_texture);
	if (game->exit_texture)
		mlx_delete_texture(game->exit_texture);
	if (game->floor_texture)
		mlx_delete_texture(game->floor_texture);
}

void	print_game_info(t_file *game)
{
	write(1, "\n", 1);
	ft_putstr_fd("Moves Counter : ", 1);
	ft_putnbr_fd(game->n_moves, 1);
	write(1, "\n", 1);
	ft_putstr_fd("Collectibles : ", 1);
	ft_putnbr_fd(game->found_collect, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(game->n_collect, 1);
	write(1, "\n", 1);
	if (game->game_is_finish == 1)
	{
		ft_putstr_fd("\nWell Done ! You Won !\n", 1);
		ft_putstr_fd("(close the window or tap ESC to close the game)\n", 1);
	}
}

void	set_player_move(t_file *game)
{
	game->found_exit = 0;
	game->found_collect = 0;
	game->game_is_finish = 0;
	game->txt_collect_count = NULL;
	game->txt_collect = NULL;
	game->txt_move_count = NULL;
	game->txt_move = NULL;
	game->exit_img = NULL;
	game->player_img = NULL;
	game->floor_img = NULL;
	game->collect_img = NULL;
	game->collect_text = NULL;
	game->exit_texture = NULL;
	game->player_texture = NULL;
	game->wall_texture = NULL;
	game->floor_texture = NULL;
}
