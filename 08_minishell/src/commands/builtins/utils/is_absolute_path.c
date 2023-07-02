#include "../../../../include/minishell.h"

bool	is_absolute_path(t_statement *statement)
{
	if (is_onstr(statement->argv[0], '/'))
		return (true);
	return (false);
}