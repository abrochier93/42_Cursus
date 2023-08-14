#include "../../include/cub3d.h"

bool	manage_settings(t_map *map, char *line)
{
	map->settings_nbr++;
	assign_path(map, line);
	if (is_id(line, "NO") && ft_file_access(map->settings[0], ".png"))
		map->north = mlx_load_png(map->settings[0]);
	else if (is_id(line, "SO") && ft_file_access(map->settings[1], ".png"))
		map->south = mlx_load_png(map->settings[1]);
	else if (is_id(line, "WE") && ft_file_access(map->settings[2], ".png"))
		map->west = mlx_load_png(map->settings[2]);
	else if (is_id(line, "EA") && ft_file_access(map->settings[3], ".png"))
		map->east = mlx_load_png(map->settings[3]);
	else if (is_id(line, "F"))
		return (manage_colors(map, 4));
	else if (is_id(line, "C"))
		return (manage_colors(map, 5));
	else
		return (false);
	return (true);
}