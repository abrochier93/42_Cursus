#include "../include/minishell.h"

extern long long	g_exit_status;

void	child_signals(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		g_exit_status = 130;
		exit(130);
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 130;
	}
}

void	config_signals(void)
{
	signal(SIGINT, signal_handler);
 	signal(SIGQUIT, SIG_IGN);
}
