/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:59:33 by gcros             #+#    #+#             */
/*   Updated: 2023/12/12 01:49:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	b;

	i = 0;
	b = (char)c;
	while (i < n)
	{
		if (((char *)s)[i] == b)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
