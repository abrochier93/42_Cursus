#include "../../include/minishell.h"

void	error(t_mini *data, char *error_msg, int exit_status)
{
	if (data)
		destroy(data);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(exit_status);
}
