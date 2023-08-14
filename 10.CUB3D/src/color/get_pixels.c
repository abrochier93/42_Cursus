#include "../../include/cub3d.h"

uint32_t	get_pixels(mlx_texture_t *image, int x, int y)
{
	return ((((uint32_t *)image->pixels)[(y * image->width + x)]));
}