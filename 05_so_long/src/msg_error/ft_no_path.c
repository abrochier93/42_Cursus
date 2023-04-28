/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:08:03 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/20 12:32:15 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_no_path(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("The actual path does NOT permit to end the game.\n", 1);
}
