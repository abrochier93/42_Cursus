/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:34:57 by abrochie          #+#    #+#             */
/*   Updated: 2023/04/06 13:50:24 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*result;

	if (!s1)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	return (result);
}
