/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 05:29:29 by gcros             #+#    #+#             */
/*   Updated: 2023/12/14 07:01:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*ft_lstshift(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	void	*data;

	if (*lst == NULL)
		return (NULL);
	tmp = *lst;
	if (tmp->next == NULL)
	{
		last = *lst;
		*lst = NULL;
	}
	else
	{
		while (tmp && tmp->next && tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
	}
	data = last->content;
	free(last);
	return (data);
}
