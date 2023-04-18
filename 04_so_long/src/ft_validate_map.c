/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:21:06 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/18 10:28:26 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_message(t_file *map)
{
	if (map->n_player != 1)
		ft_player_error();
	if (map->n_collect == 0)
		ft_no_collectible();
	if (map->n_exit != 1)
		ft_no_exit();
	if (map->n_foreign != 0)
		ft_foreign_char();
	if (map->rectangle == -1)
		ft_is_not_rectangle();
	if (map->is_close == -1)
		ft_is_not_close();
	if (map->found_collect != map->n_collect || map->found_exit == 0)
		ft_no_path();
	if (map->n_cols > 17 || map->n_rows > 17)
		ft_map_to_big();
	if (map->n_player != 1 || map->n_collect == 0 || map->n_exit != 1 || \
		map->n_foreign != 0 || map->rectangle == -1 || map->is_close == -1 ||
		map->found_collect != map->n_collect || map->found_exit  == 0 || map->n_cols > 17 || map->n_rows > 17)
		return (-1);
	return (0);
}

void	ft_check_char(int size, int index, t_file *map)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (map->map[index][i] == 'C')
			map->n_collect += 1;
		else if (map->map[index][i] == 'P')
		{
			map->p_pos.x = i;
			map->p_pos.y = index;
			map->n_player += 1;
		}
		else if (map->map[index][i] == 'E')
			map->n_exit += 1;
		else if (map->map[index][i] != '1' && map->map[index][i] != '0')
			map->n_foreign += 1;
		i++;
	}
}

void	ft_is_rectangle(t_file *map)
{
	int	i;
	int	len;

	i = 0;
	while (i < map->n_rows)
	{
		len = ft_strlen(map->map[i]);
		ft_check_char(len - 1, i, map);
		if (map->n_cols == 0)
			map->n_cols = len - 1;
		else if (map->n_cols != (len - 1))
			map->rectangle = -1;
		i++;
	}
}

void	ft_is_close(t_file *map)
{
	int		row;
	int		col;
	int		len;

	row = 0;
	while (row < map->n_rows)
	{
		col = 0;
		len = ft_strlen(map->map[row]) - 1;
		if (row == 0 || row == (map->n_rows - 1))
		{
			while (col < len)
			{
				if (map->map[row][col++] != '1')
					map->is_close = -1;
			}
		}
		else
		{
			if (map->map[row][0] != '1' || \
				map->map[row][len - 1] != '1')
				map->is_close = -1;
		}
		row++;
	}	
}

int	ft_validate_map(t_file *map)
{
	int	error;

	ft_is_rectangle(map);
	ft_is_close(map);
	ft_check_path(map);
	error = ft_print_message(map);
	if (error == -1)
		return (-1);
	return (0);
}
