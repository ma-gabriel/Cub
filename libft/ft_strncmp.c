/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:48:30 by geymat            #+#    #+#             */
/*   Updated: 2023/11/16 19:20:50 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (!length)
		return (0);
	if (!(first[i]))
		return (-second[i]);
	while (first[i] && i + 1 < length)
	{
		if (first[i] - second[i])
			return (((unsigned char) first[i]
					- (unsigned char)second[i]));
		i++;
	}
	return (((unsigned char) first[i] - (unsigned char)second[i]));
}
