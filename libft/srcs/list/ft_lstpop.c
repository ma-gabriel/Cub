/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 05:12:43 by gcros             #+#    #+#             */
/*   Updated: 2023/12/14 06:20:51 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*ft_lstpop(t_list **lst)
{
	t_list	*old;
	void	*data;

	if (*lst == NULL)
		return (NULL);
	old = *lst;
	*lst = old->next;
	data = old->content;
	free(old);
	return (data);
}
