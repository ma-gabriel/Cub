/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: androlink <androlink@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:36:01 by androlink         #+#    #+#             */
/*   Updated: 2024/01/03 12:14:04 by androlink        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

t_array	*ft_arr_new(size_t capacity)
{
	t_array	*array;

	array = (t_array *)malloc(sizeof(t_array));
	if (array == NULL)
		return (NULL);
	array->data = (void **)ft_calloc(sizeof(void *), capacity);
	if (array->data == NULL)
		return (free(array), NULL);
	array->size = 0;
	array->capacity = capacity;
	return (array);
}
