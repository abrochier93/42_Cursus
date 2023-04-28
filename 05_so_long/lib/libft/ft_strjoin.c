/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:48:09 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 14:02:35 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join_strings(char const *s1, char const *s2, char *res)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1) * 1);
	if (res == NULL)
		return (NULL);
	res = ft_join_strings(s1, s2, res);
	return (res);
}
