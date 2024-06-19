/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:02:16 by geymat            #+#    #+#             */
/*   Updated: 2023/11/16 22:30:52 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	if (!lst)
		return (NULL);
	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = f(lst->content);
	res->next = (NULL);
	if (lst->next)
		res->next = ft_lstmap(lst->next, f, del);
	if (lst->next && !res->next)
	{
		ft_lstdelone(res, del);
		return (NULL);
	}
	return (res);
}
