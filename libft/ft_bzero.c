/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:54:02 by geymat            #+#    #+#             */
/*   Updated: 2023/11/16 19:22:57 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
