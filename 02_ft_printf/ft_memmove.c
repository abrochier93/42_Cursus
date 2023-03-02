/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:05 by abrochie          #+#    #+#             */
/*   Updated: 2023/02/27 14:16:25 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*buffer1;
	char	*buffer2;

	buffer1 = (char *)src;
	buffer2 = (char *)dst;
	if (!dst || !src)
		return (NULL);
	if (buffer1 == buffer2)
		return (dst);
	if (buffer2 < buffer1)
	{
		while (len--)
			*buffer2++ = *buffer1++;
	}
	else
	{
		buffer1 += len;
		buffer2 += len;
		while (len--)
		{
			*--buffer2 = *--buffer1;
		}
	}
	return (dst);
}
