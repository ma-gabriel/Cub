/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstunshift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 06:16:25 by gcros             #+#    #+#             */
/*   Updated: 2023/12/21 09:08:25 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	ft_lstunshift(t_list **lst, void *data)
{
	t_list	*new;

	new = ft_lstnew(data);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);
	return (1);
}
