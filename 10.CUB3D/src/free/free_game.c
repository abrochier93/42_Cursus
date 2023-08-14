#include "../../include/cub3d.h"

void	free_game(t_cub *cub)
{
	free_map_line(cub->map->lines_list);
	free_map(cub->map->map);
	free_map(cub->map->settings);
	mlx_delete_texture(cub->map->east);
	mlx_delete_texture(cub->map->north);
	mlx_delete_texture(cub->map->south);
	mlx_delete_texture(cub->map->west);
	if (cub->map)
		free(cub->map);
	if (cub)
		free(cub);
}