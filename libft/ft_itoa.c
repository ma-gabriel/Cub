/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:25:08 by geymat            #+#    #+#             */
/*   Updated: 2023/11/12 19:16:31 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char		*res;
	long int	fact;
	long int	i;

	fact = 1;
	i = n < 1;
	while (fact <= (long) n * ((n > 0) * 2 - 1))
	{
		i++;
		fact *= 10;
	}
	res = (char *) ft_calloc(i + 1, 1);
	if (!res)
		return (res);
	fact = 1;
	while (n / fact && res)
	{
		res[--i] = '0' + (long)(n / fact * ((n > 0) * 2 - 1) % 10);
		fact *= 10;
	}
	if (n < 0 && res)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	return (res);
}
