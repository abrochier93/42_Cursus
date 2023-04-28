/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrochie <abrochie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:12:04 by abrochie          #+#    #+#             */
/*   Updated: 2023/02/28 14:06:23 by abrochie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*cont;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		cont = f(lst->content);
		temp = ft_lstnew(cont);
		if (!temp)
		{
			ft_lstclear(&new, *del);
			free(cont);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
