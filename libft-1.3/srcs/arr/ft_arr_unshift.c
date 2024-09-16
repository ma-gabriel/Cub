/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_unshift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:55:42 by androlink         #+#    #+#             */
/*   Updated: 2024/01/24 22:45:28 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

int	ft_arr_unshift(t_array *array, void *elem)
{
	if (array->size == array->capacity)
		return (0);
	array->size += 1;
	ft_memmove(array->data + 1,
		array->data,
		(array->size - 1) * sizeof(void *));
	array->data[0] = elem;
	return (1);
}
