/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: androlink <androlink@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:07:23 by androlink         #+#    #+#             */
/*   Updated: 2024/01/03 23:21:17 by androlink        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

void	*ft_arr_pop(t_array *array)
{
	void	*elem;

	if (array->size == 0)
		return (NULL);
	array->size -= 1;
	elem = array->data[array->size];
	array->data[array->size] = NULL;
	return (elem);
}
