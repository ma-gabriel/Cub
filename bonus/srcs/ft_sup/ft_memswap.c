/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:55:34 by gcros             #+#    #+#             */
/*   Updated: 2024/09/17 22:04:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	ft_memswapbyte(void *p1, void *p2)
{
	unsigned char	tmp;

	tmp = *(unsigned char *)p1;
	*(unsigned char *)p1 = *(unsigned char *)p2;
	*(unsigned char *)p2 = tmp;
}

void	ft_memswap(void *p1, void *p2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_memswapbyte(p1 + i, p2 + i);
		i++;
	}
}
