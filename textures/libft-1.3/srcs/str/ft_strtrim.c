/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:57:00 by gcros             #+#    #+#             */
/*   Updated: 2023/12/12 01:33:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*str;
	char		*c2;

	str = s1;
	if (!*s1 || !*set)
		return (ft_strdup(s1));
	while (ft_strchr(set, *str) && *str)
		str++;
	c2 = ft_strchr(str, '\0');
	while (str < c2 && ft_strchr(set, *(c2 - 1)))
		c2--;
	return (ft_substr(str, 0, c2 - str));
}
