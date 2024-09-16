/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:26:02 by gcros             #+#    #+#             */
/*   Updated: 2024/02/07 05:02:35 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

t_vector	*ft_vec_new(size_t	elem_size)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (vector == NULL)
		return (NULL);
	if (!ft_vec_init(vector, elem_size))
	{
		free(vector);
		vector = NULL;
	}
	return (vector);
}
