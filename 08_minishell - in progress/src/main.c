#include "../include/minishell.h"

t_global	var_global;

static void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	minishell(t_mini *shell)
{
	char	*prompt;
	t_prompt cmd_line;

	prompt = readline("miishell ~ ");
	if (!prompt)
		return (-1);
	//printf("%s\n", prompt);
	cmd_line.cmd = "env";
	cmd_line.flags = NULL;
	cmd_line.arg = NULL;
	ft_env(&cmd_line, shell);
	cmd_line.cmd = "cd";
	cmd_line.flags = NULL;
	cmd_line.arg = "~";
	ft_echo(&cmd_line);
	ft_cd(&cmd_line, shell);
	cmd_line.cmd = "env";
	cmd_line.flags = NULL;
	cmd_line.arg = NULL;
	ft_env(&cmd_line, shell);
	printf("HOME : %s\n", getenv("HOME"));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini shell;
	int mini_ret;

	(void)argv;
	//envp = NULL;
	if (!envp || !(*envp))
		return (ft_putstr_fd("Error: ENVP is missing..\n", 2), 1);
	if (argc > 1)
		return (ft_putstr_fd("Error: too many arguments.\n", 2), 1);
	ft_struct_init(envp, &shell);
	mini_ret = 0;
	while (mini_ret == 0)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
		mini_ret = minishell(&shell);
	}
	return (0);
}