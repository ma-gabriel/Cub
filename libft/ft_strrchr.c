/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:32:38 by geymat            #+#    #+#             */
/*   Updated: 2023/11/17 15:35:52 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	if (!(c % 256))
		return (str + i);
	if (!i)
		return (0);
	while (i--)
		if (str[i] == (char) c)
			return (str + i);
	return (0);
}
