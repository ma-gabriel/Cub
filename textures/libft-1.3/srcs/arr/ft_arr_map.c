/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:55:37 by androlink         #+#    #+#             */
/*   Updated: 2024/01/21 19:00:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

t_array	*ft_arr_map(t_array *array, void *(*f)(void *), void (*del)(void *))
{
	t_array	*narr;
	size_t	i;
	void	*elem;

	i = 0;
	narr = ft_arr_new(array->capacity);
	if (narr == NULL)
		return (NULL);
	while (i < array->size)
	{
		elem = f(array->data[i]);
		if (elem == NULL)
			return (ft_arr_free(&narr, del), NULL);
		ft_arr_push(narr, elem);
		i++;
	}
	return (narr);
}
