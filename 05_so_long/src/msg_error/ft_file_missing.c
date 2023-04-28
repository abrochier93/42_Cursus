/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_missing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:51:49 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/20 12:32:34 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_file_missing(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("Please provide a file.\n", 1);
}
