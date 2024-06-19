/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:24:44 by geymat            #+#    #+#             */
/*   Updated: 2023/11/12 14:41:42 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst && (*lst)->next)
		ft_lstclear(&((*lst)->next), del);
	if (*lst)
	{
		del((*lst)->content);
		free(*lst);
	}
	*lst = (NULL);
}
