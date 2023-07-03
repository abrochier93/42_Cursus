/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:56:04 by abrochie          #+#    #+#             */
/*   Updated: 2023/07/03 19:56:05 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern long long	g_exit_status;

void	exec_executables(t_statement *node, t_mini *data)
{
	char	*bin_path;

	bin_path = node->argv[0];
	if (streq(bin_path, "/usr/bin/env"))
	{
		cmd_env(data);
		return ;
	}
	if (builtin(node, data))
		return ;
	cmd_binaries(node, data);
}
