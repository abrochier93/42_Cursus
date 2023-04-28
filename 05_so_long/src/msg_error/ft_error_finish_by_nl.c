/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_finish_by_nl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:42:14 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/20 12:32:39 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_finish_by_nl(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("The file has to finish by a new line\n", 1);
}
