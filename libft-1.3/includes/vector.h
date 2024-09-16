/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 05:07:23 by gcros             #+#    #+#             */
/*   Updated: 2024/02/07 05:07:31 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>

typedef struct s_vector
{
	void	*data;
	size_t	size;
	size_t	capacity;
	size_t	elem_size;
}	t_vector;

int			ft_vec_init(t_vector *vector, size_t elem_size);
t_vector	*ft_vec_new(size_t	elem_size);
int			ft_vec_append(t_vector *vector, void *elem);
int			ft_vec_resize(t_vector *vector, size_t	ncapacity);
int			ft_vec_clear(t_vector *vector);
int			ft_vec_get(t_vector *vector, size_t index, void *out);
void		ft_vec_destroy(t_vector *vector);
void		ft_vec_free(t_vector **vector);

#endif