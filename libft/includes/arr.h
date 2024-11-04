/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:36:19 by androlink         #+#    #+#             */
/*   Updated: 2024/03/07 14:12:54 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_H
# define ARR_H

# include <stdlib.h>
# include "mem.h"

typedef struct s_array
{
	void	**data;
	size_t	size;
	size_t	capacity;
}	t_array;

t_array	*ft_arr_new(size_t capacity);
int		ft_arr_resize(t_array *array, size_t ncapacity);
void	ft_arr_clear(t_array *array, void (*del)(void *));
void	ft_arr_free(t_array **array, void (*del)(void *));
int		ft_arr_push(t_array *array, void *elem);
void	*ft_arr_pop(t_array *array);
int		ft_arr_unshift(t_array *array, void *elem);
void	*ft_arr_shift(t_array *array);
t_array	*ft_arr_map(t_array *array, void *(*f)(void *), void (*del)(void *));
int		ft_arr_append(t_array *arr, void *elem);

#endif