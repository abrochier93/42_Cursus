#include "../../include/cub3d.h"

mlx_texture_t	*get_texture(t_cub *cub, float wall[2])
{
	int	on_x;
	int	on_y;

	on_x = is_multiple_of(wall[X], cub->map->square_size);
	on_y = is_multiple_of(wall[Y], cub->map->square_size);
	if (cub->coord[X] > wall[X] && (on_x && !on_y))
		return (cub->map->west);
	else if (cub->coord[Y] < wall[Y] && (!on_x && on_y))
		return (cub->map->south);
	else if (cub->coord[X] < wall[X] && (on_x && !on_y))
		return (cub->map->east);
	else if (cub->coord[Y] > wall[Y] && (!on_x && on_y))
		return (cub->map->north);
	return (NULL);
}
