#include "../../include/cub3d.h"

int	ft_file_access(char *file, char *ext)
{
	int		fd;
	char	*str;

	if (!file)
		return (0);
	str = ft_strtrim(file, "\n");
	if (!str)
		return (0);
	if (strcmp(str + strlen(str) - strlen(ext), ext))
	{
		free(str);
		ft_msg_err(ERR_FILE_TYPE);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(str);
		ft_msg_err(ERR_FILE_OPEN);
	}
	free(str);
	close(fd);
	return (1);
}