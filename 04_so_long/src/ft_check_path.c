/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:35:38 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/04 10:35:38 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i += 1;
	}
	if (i > 0)
		free(matrix);
	matrix = NULL;
}

static char	**blank_grid(t_file *map)
{
	int		i;
	char	**grid;

	i = 0;
	grid = malloc(sizeof(char *) * (map->n_rows + 1));
	if (!grid)
		return (NULL);
	while (i < map->n_rows)
	{
		grid[i] = ft_strdup(map->map[i]);
		if (!grid[i])
		{
			free_matrix(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

static void	flood_fill(t_file *map, t_point curr, char **sol_grid)
{
	if (sol_grid[curr.y][curr.x] == '1')
		return ;
	else if (sol_grid[curr.y][curr.x] == 'C')
		map->found_collect += 1;
	else if (sol_grid[curr.y][curr.x] == 'E')
	{
		map->found_exit += 1;
		return ;
	}
	sol_grid[curr.y][curr.x] = '1';
	flood_fill(map, (t_point){curr.x + 1, curr.y}, sol_grid);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, sol_grid);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, sol_grid);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, sol_grid);
	return ;
}

void	ft_check_path(t_file *map)
{
	char	**sol_grid;

	sol_grid = blank_grid(map);
	flood_fill(map, map->p_pos, sol_grid);
	free_matrix(sol_grid);
}
