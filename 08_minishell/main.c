#include "include/minishell.h"

long long	g_exit_status = 0;

static void	clean_parsed(t_statement **statement_list, t_mini *data)
{
	p_lstclear(statement_list);
	*statement_list = NULL;
	data->head = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_mini		data;
	t_statement	*statement_list;
	char		*input;

	(void)argv;
	if (!envp || !(*envp))
 		return (ft_putstr_fd("Error: ENVP is missing..\n", 2), 1);
 	if (argc > 1)
		return (ft_putstr_fd("Error: too many arguments.\n", 2), 1);
	setup_shell(envp, &data, &statement_list);
	while (1)
	{
		input = readline("miishell~ ");
		if (!valid_input(input, &data))
			continue ;
		add_history(input);
		input = formater(input, &data);
		if (!input[0])
		{
			free(input);
			continue ;
		}
		statement_list = parser(input);
		data.head = statement_list;
		exec_type(statement_list, &data);
		clean_parsed(&statement_list, &data);
	}
	return (EXIT_SUCCESS);
}
