#include "../../include/minishell.h"

int	ft_echo(t_prompt *s_prompt)
{
	char *flag;
    char *arg;

    flag = s_prompt->flags;
    arg = s_prompt->arg;
    if (ft_strncmp(s_prompt->cmd, "echo", 5) == 0)
	{
		if (flag == NULL && arg == NULL)
			printf("\n");
		else if (ft_strncmp(flag, "-n", 3) != 0 && arg != NULL)
		{
			printf("%s\n", arg); 
		}
        else if (ft_strncmp(flag, "-n", 3) == 0 && arg != NULL)
		{
			printf("%s", arg); 
		}
        return (0);
	}
    return (1);
}