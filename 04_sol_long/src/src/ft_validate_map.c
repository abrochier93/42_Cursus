/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:21:06 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/05 15:04:06 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     ft_print_message(t_file *map)
{
    if (map->n_player != 1)
        printf("error : player number.\n");
    if (map->n_collect == 0)
        printf("error : there is no collectible.\n");
    if (map->n_exit != 1)
        printf("error : exit number.\n");
    if (map->n_foreign != 0)
        printf("nbr foreign char : %d.\n", map->n_foreign);
    if (map->rectangle == -1)
        printf("map is not rectangle");
    if (map->is_close == -1)
        printf("map is not close");
	if(map->found_collect == 0 && map->found_exit == 0)
    	printf("path is not valid");
    if (map->n_player != 1 || map->n_collect == 0 || map->n_exit != 1 || \
        map->n_foreign != 0 || map->rectangle == -1 || map->is_close == -1 || \
		map->found_collect == 0 || map->found_exit == 0)
        return (-1);
    return(0);
}

void		ft_check_char(int size, int index, t_file *map)
{
	int i;

    i = 0;
    while (i < size)
    {
        if (map->map[index][i] == 'C')
            map->n_collect += 1;
        else if (map->map[index][i] == 'P')
        {
            map->player_pos.x = i;
			map->player_pos.y = index;
            map->n_player += 1;
        }
        else if (map->map[index][i] == 'E')
            map->n_exit += 1;
        else if (map->map[index][i] != '1' && map->map[index][i]!= '0')
            map->n_foreign += 1;
        i++;
    }
}

void		ft_is_rectangle (t_file *map)
{
	int		i;
	int 	len;

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

void		ft_is_close(t_file *map)
{
	int		row;
	int		col;

	row = 0;
	while (row < map->n_rows)
	{
		col = 0;
		if (row == 0 || row == (map->n_rows - 1))
		{
			while (col < map->n_cols)
			{
				if (map->map[row][col] != '1')
					map->is_close = -1;
				col++;
			}
		}
		else 
		{
			if (map->map[row][0] != '1' || map->map[row][map->n_cols - 1] != '1')
				map->is_close = -1;
		}
		row++;
	}	
}

int		ft_validate_map(t_file *map)
{
	int     error;

	ft_is_rectangle(map);
	ft_is_close(map);
	ft_check_path(map);
	error = ft_print_message(map);
	if (error == -1)
   		return (-1);
	return(0);
}