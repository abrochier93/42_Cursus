#include "../../include/cub3d.h"

char	*ft_char_correction(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_strchr("NEWS", line[i]))
		{
			if (ft_strchr(" \t", line[i]))
				line[i] = '1';
			if (i == (int)ft_strlen(line) - 1 && line[i] != '1')
				line[i] = '1';
		}
		i++;
	}
	return (line);
}