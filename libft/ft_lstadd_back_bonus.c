/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:10:02 by geymat            #+#    #+#             */
/*   Updated: 2023/11/10 10:52:09 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst && (*lst)->next)
	{
		lst = &((*lst)->next);
	}
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	(*lst)->next = new;
}
