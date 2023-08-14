#include "../../include/cub3d.h"

t_lines_list	*ft_last_lines_list(t_lines_list *lines_list)
{
	if (!lines_list)
		return (NULL);
	while (lines_list->next)
		lines_list = lines_list->next;
	return (lines_list);
}