#include "../../include/cub3d.h"

t_lines_list	*init_lines_list(void)
{
	t_lines_list	*lines_list;

	lines_list = ft_calloc(sizeof(t_lines_list), 1);
	if (!lines_list)
		ft_msg_err(ERR_MALLOC);
	lines_list->line = NULL;
	lines_list->next = NULL;
	lines_list->prev = NULL;
	lines_list->place = 0;
	return (lines_list);
}
