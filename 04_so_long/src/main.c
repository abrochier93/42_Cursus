/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:56:21 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/13 16:35:19 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_file *file)
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
	file->p_pos.x = 0;
	file->p_pos.y = 0;
	file->rectangle = 0;
	file->is_close = 0;
	file->has_a_path = 0;
}

int	main(int ac, char **av)
{
	t_file	map;

	if (ac < 2)
	{
		ft_file_missing();
		return (0);
	}
	else if (ac > 2)
	{
		ft_to_many_file();
		return (0);
	}
	else if (ft_check_file(av[1]) == -1)
	{
		return (0);
	}
	else if (ac == 2)
	{
		ft_init_struct(&map);
		ft_init_map(av[1], &map);
		if (ft_validate_map(&map) == 0)
			ft_render_game(&map);
	}
	free_matrix(map.map);
	return (0);
}
