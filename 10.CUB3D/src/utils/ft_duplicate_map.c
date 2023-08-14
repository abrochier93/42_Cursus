#include "../../include/cub3d.h"

char	**ft_duplicate_map(char **map)
{
	int		n;
	char	**new_map;

	n = 0;
	while (map[n])
		n++;
	new_map = (char **)malloc((n + 1) * sizeof(char *));
	memcpy(new_map, map, (n + 1) * sizeof(char *));
	return (new_map);
}