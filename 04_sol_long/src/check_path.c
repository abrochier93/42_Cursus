#include "get_next_line.h"


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

void    print_tab(char **tab, int max_col, int max_rows)
{
    int y;
    int x = 0;
    while (x <= max_rows)
    {
        y = 0;
        while (y <= max_col)
        {
            printf(" %c ", tab[x][y]);
            y++;
        }
        printf("\n");
        x++;
    }
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

// static void	flood_fill(t_file *map, t_point curr, char **sol_grid)
// {

// 	if (sol_grid[curr.y][curr.x] == '1')
// 		return ;
// 	else if (sol_grid[curr.y][curr.x] == 'C')
// 		map->found_collect += 1;
// 	else if (sol_grid[curr.y][curr.x] == 'E')
// 		map->found_exit += 1;
// 	sol_grid[curr.y][curr.x] = '1';
// 	flood_fill(map, (t_point){curr.x + 1, curr.y}, sol_grid);
// 	flood_fill(map, (t_point){curr.x - 1, curr.y}, sol_grid);
// 	flood_fill(map, (t_point){curr.x, curr.y + 1}, sol_grid);
// 	flood_fill(map, (t_point){curr.x, curr.y - 1}, sol_grid);
// 	return ;
// }

void    ft_print_map_2(char **tab, t_file *map)
{
    int x;
    int y = 0;
    
    while (y <= map->n_rows)
    {
        x = 0;
        while (x <= map->n_cols)
        {
            printf("%c", tab[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}

void	ft_check_path(t_file *map)
{
	char	**sol_grid;

	sol_grid = blank_grid(map);
    ft_print_map_2(sol_grid, map);
	flood_fill(map, map->player_pos, sol_grid);
	free_matrix(sol_grid);
    if(map->found_collect != 0 && map->found_exit != 0)
    printf("path is valid");
}