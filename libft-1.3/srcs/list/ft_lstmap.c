/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:55:49 by gcros             #+#    #+#             */
/*   Updated: 2023/12/12 00:49:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*oldlst;
	void	*tmpcnt;
	t_list	*tmplst;

	oldlst = lst;
	newlst = NULL;
	while (oldlst && f)
	{
		tmpcnt = f(oldlst->content);
		tmplst = ft_lstnew(tmpcnt);
		if (!tmplst || !tmpcnt)
		{
			ft_lstclear(&newlst, del);
			if (tmpcnt && del)
				del(tmpcnt);
			if (tmplst)
				free (tmplst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmplst);
		oldlst = oldlst->next;
	}
	return (newlst);
}
