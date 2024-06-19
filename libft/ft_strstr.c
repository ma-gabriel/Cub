/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:27:37 by geymat            #+#    #+#             */
/*   Updated: 2023/11/17 15:36:34 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] == to_find[j])
			{
				j ++;
				if (!to_find[j])
					return ((char *) str + i);
			}
		}
		i++;
	}
	return (0);
}
