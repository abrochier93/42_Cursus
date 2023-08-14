#include "../../include/cub3d.h"

bool	get_player_angle(t_cub *cub)
{
	t_lines_list	*temp;

	temp = cub->map->lines_list;
	while (temp->next)
	{
		if (strchr(temp->line, 'E'))
			cub->player_angle = ft_deg_to_rad(0);
		else if (strchr(temp->line, 'W'))
			cub->player_angle = ft_deg_to_rad(180);
		else if (strchr(temp->line, 'N'))
			cub->player_angle = ft_deg_to_rad(90);
		else if (strchr(temp->line, 'S'))
			cub->player_angle = ft_deg_to_rad(270);
		temp = temp->next;
	}
	return (true);
}