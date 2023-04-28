/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_not_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:07:29 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/20 12:32:27 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_is_not_close(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("The map is NOT close by wall.\n", 1);
}
