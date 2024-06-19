/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:31:44 by geymat            #+#    #+#             */
/*   Updated: 2023/11/16 14:17:36 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(char *)(memoryBlock + i) == (char) searchedChar)
			return ((void *) memoryBlock + i);
		i++;
	}
	return (0);
}
