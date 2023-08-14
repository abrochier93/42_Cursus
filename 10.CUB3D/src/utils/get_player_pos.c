#include "../../include/cub3d.h"

bool	get_player_pos(char **map, size_t *pos)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S')
			{
				pos[Y] = i;
				pos[X] = j;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}