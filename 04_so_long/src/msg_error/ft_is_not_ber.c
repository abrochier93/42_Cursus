/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_not_ber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:18:48 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/13 15:01:30 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_not_ber(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Please provide a file .ber.\n", 1);
	return (1);
}
