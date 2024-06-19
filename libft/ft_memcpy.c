/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:04:29 by geymat            #+#    #+#             */
/*   Updated: 2023/11/16 14:25:04 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (!(dest || src))
		return (NULL);
	i = 0;
	while (i < count)
	{
		*(char *)dest = *(char *)(src + i);
		dest ++;
		i++;
	}
	return (dest - count);
}
