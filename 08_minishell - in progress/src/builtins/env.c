#include "../../include/minishell.h"

int	ft_env(t_prompt *s_prompt, t_mini *data)
{
	if (ft_strncmp(s_prompt->cmd, "env", 4) == 0)
	{
		ft_print_env(data->env_cpy);
        return (0);
	}
    return (1);
}