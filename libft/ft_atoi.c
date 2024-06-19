/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geymat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:59:49 by geymat            #+#    #+#             */
/*   Updated: 2024/02/02 01:30:15 by geymat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long int	res;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	i--;
	while (str[++i] <= '9' && str[i] >= '0')
	{
		if (res * 10 + (str[i] - '0') < res)
			return (-(sign == 1));
		res = res * 10 + (str[i] - '0');
	}
	return ((int)(res * sign));
}
