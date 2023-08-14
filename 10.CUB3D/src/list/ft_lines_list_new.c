#include "../../include/cub3d.h"

t_lines_list	*ft_lines_list_new(char *line)
{
	t_lines_list	*lines_list;

	lines_list = malloc(sizeof(t_lines_list));
	if (!lines_list)
		return (NULL);
	lines_list->line = line;
	lines_list->next = NULL;
	lines_list->prev = NULL;
	return (lines_list);
}