/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:57:43 by abrochie          #+#    #+#             */
/*   Updated: 2023/07/03 19:57:44 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_free(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len_s1)
		res[i++] = s1[j++];
	j = 0;
	while (j < len_s2)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}
