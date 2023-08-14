#include "../../include/cub3d.h"

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		ft_msg_err(ERR_MALLOC);
	cub->map = init_map();
	cub->coord[X] = 0;
	cub->coord[Y] = 0;
	cub->distance_x = 0;
	cub->distance_y = 0;
	cub->p_dir = 0;
	return (cub);
}