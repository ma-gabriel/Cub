/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:53:22 by geymat            #+#    #+#             */
/*   Updated: 2023/11/16 19:19:20 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		j = ++i;
	i = 0;
	while (src[i] && i + j + 1 < size)
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[j + i] = 0;
	i = 0;
	while (src[i])
		i++;
	if (size > j)
		return (i + j);
	return (size + i);
}
