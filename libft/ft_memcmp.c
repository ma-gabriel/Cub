/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:34:42 by geymat            #+#    #+#             */
/*   Updated: 2023/11/16 14:18:17 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	int		temp;

	i = 0;
	while (i < n)
	{
		temp = *(unsigned char *)(str1 + i) - *(unsigned char *)(str2 + i);
		if (temp)
			return (temp);
		i++;
	}
	return (0);
}
