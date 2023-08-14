#include "../../include/cub3d.h"

bool	is_playable(t_cub *cub)
{
	size_t	pos[2];
	char	**new_map;
	bool	is_closed;

	if (!get_player_pos(cub->map->map, pos))
		return (ft_msg_err(ERR_PLAYER_POSITION));
	cub->coord[X] = pos[0];
	cub->coord[Y] = pos[1];
	new_map = ft_duplicate_map(cub->map->map);
	if (!new_map)
		return (ft_msg_err(ERR_MALLOC));
	is_closed = floodfill(cub, new_map, pos[0], pos[1]);
	if (!is_closed)
	{
		free_map(new_map);
		return (ft_msg_err(ERR_WALLS));
	}
	free(new_map);
	return (true);
}

bool	floodfill(t_cub *cub, char **new_map, int i, int j)
{
	bool	is_closed;

	if (i < 0 || i >= cub->map->height - 1 || j < 0 || j >= cub->map->width)
		return (false);
	if (cub->map->map[i][j] == '1' || new_map[i][j] == true)
		return (true);
	else
		new_map[i][j] = true;
	is_closed = true;
	is_closed &= floodfill(cub, new_map, i - 1, j);
	is_closed &= floodfill(cub, new_map, i + 1, j);
	is_closed &= floodfill(cub, new_map, i, j - 1);
	is_closed &= floodfill(cub, new_map, i, j + 1);
	return (is_closed);
}
