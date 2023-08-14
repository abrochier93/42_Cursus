#include "../../include/cub3d.h"

void	draw_wall(t_cub *cub, float wall[2], int pos_x)
{
	int			j;
	float		distance;
	uint32_t	color;

	distance = sqrtf(powf(wall[X] - cub->coord[X], 2) + powf(wall[Y]
				- cub->coord[Y], 2));
	distance = (cub->map->square_size * HEIGHT / distance);
	if (distance >= HEIGHT)
		distance = HEIGHT;
	j = HEIGHT * 0.5 - (distance * 0.5);
	while (j < (HEIGHT * 0.5) + distance * 0.5)
	{
		if (cub->texture)
			color = get_pixels(cub->texture, pos_x % cub->texture->width, j
					% cub->texture->height);
		else
			color = 0xF6c7a89;
		mlx_put_pixel(cub->win, pos_x, j, color);
		j++;
	}
}