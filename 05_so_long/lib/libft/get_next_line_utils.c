/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:30:05 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/04 09:30:05 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero_gnl(void *b, size_t len)
{
	while (len--)
		((char *)b)[len] = 0;
}

void	*ft_str_free_gnl(void *str)
{
	free(str);
	return (NULL);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	while (!res)
		res = malloc(count * size);
	ft_bzero_gnl(res, count * size);
	return (res);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	res = ft_calloc_gnl(s1_len + s2_len + 1, sizeof(char));
	if (!res)
		return (res = ft_str_free_gnl(res), NULL);
	while (s1_len + s2_len-- > s1_len)
		res[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		res[s1_len] = s1[s1_len];
	if (*res == 0)
		res = ft_str_free_gnl(res);
	return (ft_str_free_gnl(s1), res);
}
