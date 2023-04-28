/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:05:32 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/20 12:32:12 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_player_error(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Player number is NOT valid.\n", 1);
}
