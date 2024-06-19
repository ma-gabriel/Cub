/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:07 by geymat            #+#    #+#             */
/*   Updated: 2023/11/17 16:00:26 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	find_end(char const *s1, char const *set)
{
	size_t	set_i;
	size_t	i;
	size_t	temp;
	size_t	check;

	if (!(*(s1 + 1)))
		return (-1);
	temp = 0;
	i = -1;
	while (s1[++i])
	{
		set_i = -1;
		check = 1;
		while (set[++set_i])
			if (s1[i] == set[set_i])
				check = 0;
		if (check)
			temp = i;
	}
	return (temp);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char		*res;
	size_t		temp;
	size_t		set_i;
	size_t		i;
	char const	*s1;

	temp = 1;
	s1 = s - 1;
	while (*++s1 && temp)
	{
		temp = 0;
		set_i = -1;
		while (set[++set_i])
			if (*s1 == set[set_i])
				temp = 1;
	}
	temp = find_end(--s1, set);
	res = (char *) malloc((temp + 2));
	if (!res)
		return (NULL);
	i = -1;
	while (++i + 1 <= temp + 1)
		res[i] = s1[i];
	res[temp + 1] = 0;
	return (res);
}
