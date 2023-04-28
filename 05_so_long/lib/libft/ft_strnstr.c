/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:44:16 by abrochie          #+#    #+#             */
/*   Updated: 2023/02/27 14:44:22 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!to_find || !str)
		return (NULL);
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while ((str[i + j] == to_find[j] && str[i + j] != '\0') && i + j < n)
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
