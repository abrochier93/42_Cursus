#include "../../include/cub3d.h"

char	*get_path(char *line_in, char *str)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	line = ft_strtrim(line_in, "\n");
	while (line && line[i] && ft_iswhitespace(line[i]))
		i++;
	if (!ft_strncmp(&line[i], str, strlen(str)))
	{
		i += strlen(str);
		while (ft_iswhitespace(line[i]))
			i++;
		tmp = ft_strdup(&line[i]);
		free(line);
		return (tmp);
	}
	else
	{
		free(line);
		return (NULL);
	}
}