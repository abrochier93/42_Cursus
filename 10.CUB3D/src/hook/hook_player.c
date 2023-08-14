#include "../../include/cub3d.h"

void	hook_player(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	moves(cub);
	rotate(cub);
	render_fov(cub);
}