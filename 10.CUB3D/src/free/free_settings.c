#include "../../include/cub3d.h"

void	free_settings(char **settings)
{
	int	i;

	i = 0;
	while (i < 7)
		free(settings[i++]);
	free(settings);
}