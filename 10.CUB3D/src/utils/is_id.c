#include "../../include/cub3d.h"

bool	is_id(char *line, char *str)
{
	char	*tmp;

	tmp = get_path(line, str);
	if (tmp)
	{
		free(tmp);
		return (true);
	}
	free(tmp);
	return (false);
}


