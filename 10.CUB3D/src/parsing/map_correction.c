#include "../../include/cub3d.h"

bool	map_correction(t_cub *cub)
{
	int	i;

	if (!cub->map->map)
		return (false);
	i = 0;
	while (i < cub->map->height)
	{
		cub->map->map[i] = ft_char_correction(cub->map->map[i]);
		i++;
	}
	return (true);
}