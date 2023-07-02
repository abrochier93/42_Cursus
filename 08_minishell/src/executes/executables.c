#include "../../include/minishell.h"

extern long long	g_exit_status;

void	exec_executables(t_statement *node, t_mini *data)
{
	if (builtin(node, data))
		return ;
	cmd_binaries(node, data);
}
