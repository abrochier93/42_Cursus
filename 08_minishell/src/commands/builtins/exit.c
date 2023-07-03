/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:55:29 by abrochie          #+#    #+#             */
/*   Updated: 2023/07/03 19:55:30 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

extern long long	g_exit_status;

static void	exit_non_numeric_arg(void)
{
	g_exit_status = 2;
	ft_putendl_fd(EXIT_NON_NUMERIC_ARG, STDERR_FILENO);
}

void	cmd_exit(t_statement *s, t_mini *data)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (s->argc == 2)
	{
		if (is_all_digits_or_signals(s->argv[1]))
			g_exit_status = ft_atoi(s->argv[1]);
		else
			exit_non_numeric_arg();
	}
	else if (s->argc > 2)
	{
		g_exit_status = EXIT_FAILURE;
		ft_putendl_fd(EXIT_TOO_MANY_ARGS, STDERR_FILENO);
	}
	else
		g_exit_status = EXIT_SUCCESS;
	if (data)
		destroy(data);
	exit(g_exit_status);
}
