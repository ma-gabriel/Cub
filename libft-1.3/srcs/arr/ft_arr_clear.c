/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: androlink <androlink@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:06:48 by androlink         #+#    #+#             */
/*   Updated: 2024/01/02 23:26:57 by androlink        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

void	ft_arr_clear(t_array *array, void (*del)(void *))
{
	if (del)
		while (array->size-- > 0)
			del(array->data[array->size]);
}
