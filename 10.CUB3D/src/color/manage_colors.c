#include "../../include/cub3d.h"

bool	manage_colors(t_map *map, int line)
{
	if (line == 4 && map->settings[4])
	{
		if (!load_color(&map->floor, map->settings[4]))
			return (false);
	}
	else if (line == 5 && map->settings[5])
	{
		if (!load_color(&map->ceiling, map->settings[5]))
			return (false);
	}
	return (true);
}