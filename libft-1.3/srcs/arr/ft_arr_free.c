/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: androlink <androlink@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:04:54 by androlink         #+#    #+#             */
/*   Updated: 2024/01/02 23:26:25 by androlink        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

void	ft_arr_free(t_array **array, void (*del)(void *))
{
	ft_arr_clear(*array, del);
	free((*array)->data);
	free(*array);
	*array = NULL;
}
