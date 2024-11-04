/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:00:17 by gcros             #+#    #+#             */
/*   Updated: 2023/12/12 01:33:46 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static size_t	ft_min(size_t n1, size_t n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	l;
	size_t	i;
	char	*ptr;

	l = ft_strlen(s);
	i = 0;
	l = ft_min(l - start, len) * (l > start);
	ptr = (char *)malloc(l + 1);
	if (!ptr)
		return (ptr);
	while (i < l)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
