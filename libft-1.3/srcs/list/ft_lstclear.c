/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:49:08 by gcros             #+#    #+#             */
/*   Updated: 2023/12/12 00:49:25 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	*lst = NULL;
	while (ptr)
	{
		next = ptr->next;
		if (del)
			del(ptr->content);
		free(ptr);
		ptr = next;
	}
}
