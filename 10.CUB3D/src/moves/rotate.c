#include "../../include/cub3d.h"

void	rotate(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->player_angle -= 0.08;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->player_angle += 0.08;
}