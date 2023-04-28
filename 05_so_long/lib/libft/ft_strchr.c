/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:57:22 by abrochie          #+#    #+#             */
/*   Updated: 2023/02/27 13:32:03 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c2;

	c2 = c;
	if (!s)
		return (NULL);
	while (*s != c2 && *s != '\0')
		s++;
	if (*s == '\0')
	{
		if (c2 != '\0')
			return (NULL);
		else
			return ((char *)s);
	}
	return ((char *)s);
}
