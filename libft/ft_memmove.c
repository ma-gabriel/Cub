/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 03:26:58 by geymat            #+#    #+#             */
/*   Updated: 2023/11/16 14:25:28 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (src == dest)
		return (dest);
	if ((unsigned char *) src > (unsigned char *) dest)
	{
		i = 0;
		while (i < count)
		{
			*(char *)dest = *(char *)(src + i);
			dest ++;
			i++;
		}
		return (dest - count);
	}
	i = (unsigned long int) count + 1;
	dest += i - 2 ;
	while (--i > 0)
	{
		*(char *)dest = *(char *)(src + i - 1);
		dest --;
	}
	return (++dest);
}
