#include "../../../include/minishell.h"

void	ft_print_env(char **env)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (env[i] != NULL)
	{
		while (env[i][++j] != '\0')
			write(1, &env[i][j], 1);
		j = -1;
		i++;
		write(1, "\n", 1);
	}
}