#include "../../include/cub3d.h"

bool	parsing(t_cub *cub, char *file)
{
	int	fd;

	if (!ft_file_access(file, ".cub"))
		return (ft_msg_err(ERR_FILE_FOUND));
	fd = open(file, O_RDONLY);
	if (!store_map(cub, fd))
		ft_msg_err_close(ERR_MAP, &fd);
	close(fd);
	if (!map_is_valid(cub))
		return (false);
	cub->map->map = ft_list_to_array(cub->map);
	if (!cub->map->map)
		return (false);
	if (!is_playable(cub) || !map_correction(cub))
		return (false);
	return (true);
}
