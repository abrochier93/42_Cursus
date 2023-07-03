/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:57:27 by abrochie          #+#    #+#             */
/*   Updated: 2023/07/03 19:57:28 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_vars2(size_t *i, bool *in_quotes)
{
	*i = -1;
	*in_quotes = false;
}

void	quotes_onstr(bool *in_quotes, char c)
{
	if (is_onstr(QUOTES, c))
		*in_quotes = !in_quotes;
}
