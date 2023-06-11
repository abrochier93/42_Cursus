#include "../../include/minishell.h"

char	**ft_cpy_env(char **envp)
{
	char	**copy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	copy = ft_calloc((i + 1), sizeof(char *));
	i = 0;
	while (envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void    ft_struct_init(char **envp, t_mini *shell)
{
    shell->env_cpy = ft_cpy_env(envp);
    shell->pwd = NULL;
}