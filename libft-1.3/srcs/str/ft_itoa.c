/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:38:36 by gcros             #+#    #+#             */
/*   Updated: 2023/12/12 01:55:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static size_t	ft_countdigit(long long n)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n / 10 > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static size_t	ft_reqitoa(long long n, char *str)
{
	size_t	stackcount;

	stackcount = (*str == '-');
	if (n / 10)
		stackcount = ft_reqitoa(n / 10, str) + 1;
	str[stackcount] = '0' + (n % 10);
	return (stackcount);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;
	long long	ln;

	ln = (long long) n;
	size = ft_countdigit(ln);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	*str = '\0';
	if (n < 0)
	{
		ln = -ln;
		ft_strlcat(str, "-", size + 1);
	}
	ft_reqitoa(ln, str);
	str[size] = '\0';
	return (str);
}
