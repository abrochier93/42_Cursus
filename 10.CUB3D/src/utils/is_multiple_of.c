#include "../../include/cub3d.h"

bool	is_multiple_of(float pos, int x)
{
	int	coord;

	coord = (int)floorf(pos);
	if ((coord % x) == 0 || (coord + 1) % x == 0) 
		return (true);
	return (false);
}