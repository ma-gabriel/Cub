/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 02:57:26 by gcros             #+#    #+#             */
/*   Updated: 2024/02/13 22:08:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

int	ft_arr_append(t_array *arr, void *elem)
{
	if (arr->size == arr->capacity)
		if (ft_arr_resize(arr, arr->size + 20) == 0)
			return (0);
	arr->data[arr->size] = elem;
	arr->size++;
	return (1);
}
