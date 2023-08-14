#include "../../include/cub3d.h"

bool	store_map_infos(t_cub *cub, char *line)
{
	if (is_type_line(line) == 1)
	{
		ft_lines_list_add_back(&cub->map->lines_list, line);
		cub->map->height++;
		if ((int)strlen(line) > cub->map->width)
			cub->map->width = strlen(line);
	}
	else if (is_type_line(line) == 2)
	{
		if (!manage_settings(cub->map, line))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	else if (is_type_line(line) == 3)
	{
		free(line);
		return (false);
	}
	return (true);
}


