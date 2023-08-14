#include "../../include/cub3d.h"

void	moves(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_UP) || mlx_is_key_down(cub->mlx, MLX_KEY_W))
	{
		cub->distance_x = cosf(cub->player_angle);
		cub->distance_y = -sinf(cub->player_angle);
		adjust(cub, cub->distance_x, cub->distance_y, '+');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_DOWN) || mlx_is_key_down(cub->mlx, MLX_KEY_S))
	{
		cub->distance_x = cosf(cub->player_angle);
		cub->distance_y = -sinf(cub->player_angle);
		adjust(cub, cub->distance_x, cub->distance_y, '-');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
	{
		cub->distance_x = cosf((cub->player_angle + ft_deg_to_rad(90)));
		cub->distance_y = -sinf((cub->player_angle + ft_deg_to_rad(90)));
		adjust(cub, cub->distance_x, cub->distance_y, '+');
	}
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
	{
		cub->distance_x = -cosf((cub->player_angle - ft_deg_to_rad(90)));
		cub->distance_y = sinf((cub->player_angle - ft_deg_to_rad(90)));
		adjust(cub, cub->distance_x, cub->distance_y, '-');
	}
}