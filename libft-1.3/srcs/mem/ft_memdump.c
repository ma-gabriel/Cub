/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:22:22 by gcros             #+#    #+#             */
/*   Updated: 2024/08/13 15:50:52 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "unistd.h"

void	print_v(unsigned char byte)
{
	char	p[2];

	p[1] = "0123456789abcdef"[byte & 0XF];
	p[0] = "0123456789abcdef"[(byte >> 4) & 0XF];
	write(1, p, 2);
}

void	ft_memdump(void *p, size_t len)
{
	size_t	i;

	i = 0;
	while (len--)
	{
		print_v(((unsigned char *)p)[i]);
		if (len)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
