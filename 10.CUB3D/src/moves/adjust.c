#include "../../include/cub3d.h"

void	adjust(t_cub *cub, float dx, float dy, unsigned char flag)
{
	dx *= 12;
	dy *= 12;
	if (flag == '+')
	{
		if (!is_wall(cub, cub->coord[X] + cub->distance_x * 12, 
			cub->coord[Y] + cub->distance_y * 12))
		{
			cub->coord[X] += dx;
			cub->coord[Y] += dy;
		}
	}
	if (flag == '-')
	{
		if (!is_wall(cub, cub->coord[X] - cub->distance_x * 12, 
			cub->coord[Y] - cub->distance_y * 12))
		{
			cub->coord[X] -= dx;
			cub->coord[Y] -= dy;
		}
	}
}