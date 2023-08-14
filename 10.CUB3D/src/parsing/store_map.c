#include "../../include/cub3d.h"

bool	store_map(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_msg_err_close(ERR_FILE_EMPTY, &fd);
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (!store_map_infos(cub, line))
				return (false);
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	if (cub->map->settings_nbr != 6 || !cub->map->settings[0] || !cub->map->settings[1]
		|| !cub->map->settings[2] || !cub->map->settings[3] || !cub->map->settings[4]
		|| !cub->map->settings[5])
	{
		free_settings(cub->map->settings);
		return (false);
	}
	return (true);
}