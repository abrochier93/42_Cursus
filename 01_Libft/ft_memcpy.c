/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:56:56 by abrochie          #+#    #+#             */
/*   Updated: 2023/02/27 13:57:02 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	const char		*buffer1;
	char			*buffer2;

	i = 0;
	buffer1 = (char *)src;
	buffer2 = dst;
	if (!dst || !src)
		return (dst);
	while (i < n && (src || dst))
	{
		buffer2[i] = buffer1[i];
		i++;
	}
	return (dst);
}
