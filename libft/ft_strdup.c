/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:32:06 by geymat            #+#    #+#             */
/*   Updated: 2023/11/17 15:32:08 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;
	size_t	len;

	i = -1;
	len = 0;
	while (src[len])
		len++;
	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (++i < len)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}
