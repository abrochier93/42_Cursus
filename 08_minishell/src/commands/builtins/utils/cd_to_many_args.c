#include "../../../../include/minishell.h"

int	cd_too_many_args(void)
{
	ft_putendl_fd(CD_TOO_MANY_ARGS, STDERR_FILENO);
	return (EXIT_FAILURE);
}
