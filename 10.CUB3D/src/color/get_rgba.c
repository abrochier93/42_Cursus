#include "../../include/cub3d.h"

UINT	get_rgba(int r, int g, int b, int a)
{
	UINT color;

	color = 0;
	color |= r << 24;
	color |= g << 16;
	color |= b << 8;
	color |= a;
	return (color);
}