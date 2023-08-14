#include "../../include/cub3d.h"

void	ft_lines_list_add_back(t_lines_list **lines_list, char *line)
{
	t_lines_list	*new;
	t_lines_list	*last;

	new = ft_lines_list_new(line);
	last = ft_last_lines_list(*lines_list);
	if (!last->line)
	{
		(*lines_list) = new;
		free(last);
		(*lines_list)->place++;
	}
	else
	{
		last->next = new;
		new->prev = last;
		(*lines_list)->place++;
	}
}