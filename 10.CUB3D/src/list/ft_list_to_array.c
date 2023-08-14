#include "../../include/cub3d.h"

char	**ft_list_to_array(t_map *mini_map)
{
	t_lines_list	*lines_list;
	char		**map;
	int			i;

	i = 0;
	map = ft_calloc(mini_map->height, sizeof(char *));
	if (!map)
		return (NULL);
	lines_list = mini_map->lines_list;
	while (lines_list)
	{
		map[i] = ft_strdup(lines_list->line);
		lines_list = lines_list->next;
		i++;
	}
	return (map);
}