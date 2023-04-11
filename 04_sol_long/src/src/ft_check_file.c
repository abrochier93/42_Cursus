/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:10:15 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/04 08:50:47 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i + 1] == 'b' && str[i + 2] == 'e' \
		&& str[i + 3] == 'r' && str[i + 4] == '\0')
		return (0);
	return (1);
}

int	ft_check_file(char *str) 
{
	if (ft_is_ber(str) == 1)
		return (ft_is_not_ber(), -1);
	return (0);
}
