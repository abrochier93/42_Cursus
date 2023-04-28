/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_start_by_nl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:02:04 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/20 13:11:58 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_start_by_nl(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("The file should NOT start by a new line\n", 1);
}
