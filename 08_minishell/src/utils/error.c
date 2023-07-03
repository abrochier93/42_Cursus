/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:57:15 by abrochie          #+#    #+#             */
/*   Updated: 2023/07/03 19:57:16 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	error(t_mini *data, char *error_msg, int exit_status)
{
	if (data)
		destroy(data);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(exit_status);
}
