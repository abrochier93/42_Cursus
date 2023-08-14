#include "../../include/cub3d.h"

int	ft_arraylen(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}


