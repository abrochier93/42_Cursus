#include "../../include/cub3d.h"

void	free_map_line(t_lines_list *lines_list)
{
	t_lines_list	*temp;

	while (lines_list)
	{
		temp = lines_list;
		lines_list = lines_list->next;
		free(temp->line);
		free(temp);
	}
}
