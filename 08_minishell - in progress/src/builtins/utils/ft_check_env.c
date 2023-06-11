#include "../../../include/minishell.h"

int	ft_check_env(char **env, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (var == NULL)
	{
		while (env[i] != NULL)
			i++;
		return (i);
	}
	while (env[i] != NULL)
	{
		while (env[i][j] == var[j] && var[j] != '\0')
			j++;
		if (var[j] == '\0' && env[i][j] == '=')
			break ;
		j = 0;
		i++;
	}
	if (env[i] == NULL)
		return (-1);
	return (i);
}