/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:41:56 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 14:00:57 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		s_len;
	char	c2;

	c2 = c;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	s += s_len;
	if (*s == '\0' && c2 == '\0')
		return ((char *)s);
	while (s_len >= 0)
	{
		if (*s == c2)
			return ((char *)s);
		s--;
		s_len--;
	}
	return (NULL);
}
