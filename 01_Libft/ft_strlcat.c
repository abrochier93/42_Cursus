/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:47:29 by abrochie          #+#    #+#             */
/*   Updated: 2023/02/27 14:47:34 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	dst_len;

	i = ft_strlen(dst);
	dst_len = ft_strlen(dst);
	y = 0;
	if (dstsize && ft_strlen(dst) <= dstsize)
	{
		while (src[y] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[y];
			i++;
			y++;
		}
		dst[i] = '\0';
	}
	if (dstsize == 0)
		dst_len = 0;
	if (dstsize < dst_len)
		dst_len = dstsize;
	return (dst_len + ft_strlen((char *)src));
}
