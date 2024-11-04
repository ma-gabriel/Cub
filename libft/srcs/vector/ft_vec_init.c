/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:24:08 by gcros             #+#    #+#             */
/*   Updated: 2024/02/07 05:04:11 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

int	ft_vec_init(t_vector *vector, size_t elem_size)
{
	vector->data = malloc(0);
	if (vector->data == NULL)
		return (0);
	vector->size = 0;
	vector->elem_size = elem_size;
	vector->capacity = 0;
	return (1);
}
