/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: androlink <androlink@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:02:38 by androlink         #+#    #+#             */
/*   Updated: 2024/01/03 23:21:03 by androlink        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

int	ft_arr_push(t_array *array, void *elem)
{
	if (array->size == array->capacity)
		return (0);
	array->data[array->size] = elem;
	array->size += 1;
	return (1);
}
