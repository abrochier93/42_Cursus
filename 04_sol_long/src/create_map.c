#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen((char *)s1);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}


char	**ft_close_file(int fd, char **result[])
{
	if (close(fd) == 0)
		return (*result);
	else
	{
		free(*result);
		perror("Error\n");
		exit(0);
	}
}	

char	**ft_create_map(char *file, t_file *map)
{
	int		fd;
	char	**result;
	char	*line;
	int		i;

	i = 0;
	fd = ft_open_file(file);
	result = malloc(sizeof(char *) * (map->n_rows + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		result[i] = ft_strdup(line);
		free(line);
		i++;
	}
	result[i] = "\n";
	return (ft_close_file(fd, &result));
}
