/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:28:21 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 14:28:34 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(char *map_file, t_game *game)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	temp = "";
	while (i < game->map_row)
	{
		temp = get_next_line(fd);
		ft_strlcpy(game->maps[i], temp, game->map_col);
		i++;
		free(temp);
	}
	close(fd);
	game->game_state++;
}

void	set_game_size(t_game *game)
{
	int	i;

	i = 0;
	game->collect_col = ft_calloc(sizeof(int), game->map_collectible + 1);
	game->collect_row = ft_calloc(sizeof(int), game->map_collectible + 1);
	game->wall_col = ft_calloc(sizeof(int), game->map_wall + 1);
	game->wall_row = ft_calloc(sizeof(int), game->map_wall + 1);
	game->floor_col = ft_calloc(sizeof(int), game->map_floor + 1);
	game->floor_row = ft_calloc(sizeof(int), game->map_floor + 1);
	game->maps = ft_calloc(sizeof(char *), game->map_row + 1);
	game->wall = ft_calloc(sizeof(mlx_image_t *), game->map_wall);
	game->floor = ft_calloc(sizeof(mlx_image_t *), game->map_floor);
	game->collect = ft_calloc(sizeof(mlx_image_t *), game->map_collectible);
	game->value_map = ft_calloc(sizeof(int *), game->map_row + 1);
	while (i < game->map_row)
		game->maps[i++] = ft_calloc(sizeof(char), game->map_col + 1);
	i = 0;
	while (i < game->map_row)
		game->value_map[i++] = ft_calloc(sizeof(int), game->map_col + 1);
	game->game_state++;
}

void	set_direction(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (i < game->map_row)
	{
		j = 1;
		while (j < game->map_col)
		{
			count = calcul_count_pos(game, i, j);
			game->value_map[i][j] = count;
			j++;
		}
		i++;
	}
	game->value_map[i] = NULL;
}