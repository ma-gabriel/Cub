/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:19:35 by gcros             #+#    #+#             */
/*   Updated: 2024/02/07 05:02:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "mem.h"

int	ft_vec_get(t_vector *vector, size_t index, void *out)
{
	if (index >= vector->size)
		return (0);
	ft_memcpy(out, vector->data + vector->elem_size * index, vector->elem_size);
	return (1);
}
