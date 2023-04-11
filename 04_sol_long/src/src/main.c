/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:56:21 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 15:02:37 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_init_struct(t_file *file)
{
	file->mlx = NULL;
    file->map = NULL;
    file->n_collect = 0;
    file->n_player = 0;
    file->n_exit = 0;
    file->n_cols = 0;
    file->n_moves = 0;
    file->n_rows = 0;
    file->n_foreign = 0;
    file->found_collect = 0;
    file->found_exit = 0;
    file->player_pos.x = 0;
    file->player_pos.y = 0;
    file->rectangle = 0;
    file->is_close = 0;
    file->has_a_path = 0;
}

int	main(int ac, char **av)
{
	t_file	map;
	// int map_error;
	// int y = 0;
	// int x = 0;

	if (ac < 2)
		ft_file_missing();
	else if (ac > 2)
		ft_to_many_file();
	else if (ft_check_file(av[1]) == -1)
		return (0);
	else if (ac == 2)
	{
		ft_init_struct(&map);
		ft_init_map(av[1], &map);
		ft_validate_map(&map);
		ft_render_game(&map);
		//si return -1 return (0)
		//ft_launch_game(&map);
	}
	printf("Nombre de player : %d\n", map.n_player);
	printf("Nombre de collectible : %d\n", map.n_collect);
	printf("Nombre de exit : %d\n", map.n_exit);
	printf("Nombre de colonnes : %d\n", map.n_cols);
	printf("Nombre de lignes : %d\n", map.n_rows);
	printf("Nombre de foreign char : %d\n", map.n_foreign);
	printf("Coordonnées du joueur tab[%d][%d]\n", map.player_pos.y, map.player_pos.x);
	//ft_render_map(map);

	// while (y < map.n_rows)
	// {
	// 	x = 0;
	// 	while (x < map.n_cols)
	// 	{
	// 		write(1, &map.map[y][x], 1);
	// 		x++;
	// 	}
	// 	write(1, "\n", 1);
	// 	y++;
	// }
	free_matrix(map.map);
	return (0);
}