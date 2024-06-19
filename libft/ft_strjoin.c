/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:10:47 by geymat            #+#    #+#             */
/*   Updated: 2023/11/17 15:32:58 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	temp;
	char	*res;

	i = 0;
	while (s1[i])
		i++;
	temp = i;
	i = 0;
	while (s2[i])
		i++;
	res = (char *) malloc((i + temp + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	i = -1;
	while (s2[++i])
		res[i + temp] = s2[i];
	res[i + temp] = 0;
	return (res);
}
