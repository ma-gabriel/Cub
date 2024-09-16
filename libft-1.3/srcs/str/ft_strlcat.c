/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:01:42 by gcros             #+#    #+#             */
/*   Updated: 2023/12/12 01:33:26 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sdst;

	i = 0;
	sdst = ft_strlen(dst);
	if (size == 0 || sdst > size)
		return (size + ft_strlen(src));
	while (sdst + i < size - 1 && src[i])
	{
		dst[sdst + i] = src[i];
		i++;
	}
	dst[sdst + i] = '\0';
	return (sdst + ft_strlen(src));
}
