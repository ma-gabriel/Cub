/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:09:36 by gcros             #+#    #+#             */
/*   Updated: 2023/12/14 06:27:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printnbr(long long llnbr)
{
	size_t	count;

	count = 0;
	if (llnbr < 0)
		return (write(1, "-", 1) + ft_printnbr(-llnbr));
	if (llnbr / 10 != 0)
		count += ft_printnbr(llnbr / 10);
	return (count + ft_printchar((llnbr % 10) + '0'));
}
