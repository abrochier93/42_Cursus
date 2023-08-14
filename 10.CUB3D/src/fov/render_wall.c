#include "../../include/cub3d.h"

bool	render_wall(t_cub *cub, float angle, int pos_x)
{
	int		i;
	float	x;
	float	y;
	float	wall[2];

	i = 0;
	cub->ray_x = cos((angle));
	cub->ray_y = -sin((angle));
	while (1)
	{
		x = cub->coord[X] + cub->ray_x * i;
		y = cub->coord[Y] + cub->ray_y * i;
		if (is_wall(cub, x, y))
		{
			wall[X] = x;
			wall[Y] = y;
			cub->texture = get_texture(cub, wall);
			draw_wall(cub, wall, pos_x);
			return (false);
		}
		i++;
	}
	return (true);
}
