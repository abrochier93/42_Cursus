#include "../../include/cub3d.h"

bool	is_wall(t_cub *cub, float destx, float desty)
{
	int	x;
	int	y;

	x = (int)floorf(destx / cub->map->square_size);
	y = (int)floorf(desty / cub->map->square_size);
	return (cub->map->map[y][x] == '1');
}