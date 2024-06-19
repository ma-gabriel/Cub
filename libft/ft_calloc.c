/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:35:47 by geymat            #+#    #+#             */
/*   Updated: 2023/11/24 02:13:44 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t num, size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	if (num && size && ((num * size) / num != size))
		return (NULL);
	res = (char *) malloc(num * size);
	if (!res)
		return (NULL);
	while (i < num * size)
	{
		res[i] = 0;
		i++;
	}
	return ((void *) res);
}
