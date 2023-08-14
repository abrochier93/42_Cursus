#include "../../include/cub3d.h"

void	render_fov(t_cub *cub)
{
	float	i;
	float	incr;

	i = 0;
	incr = 0;
	cub->starting_a = cub->player_angle + (cub->fov * 0.5);
	incr = cub->fov / WIDTH;
	while (i < WIDTH)
	{
		render_wall(cub, cub->starting_a, i);
		cub->starting_a -= incr;
		i++;
	}
}
