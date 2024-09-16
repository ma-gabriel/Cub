/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:51:44 by gcros             #+#    #+#             */
/*   Updated: 2023/12/14 06:27:44 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printptr(unsigned long long ullnbr)
{
	if (ullnbr == 0)
		return (write(1, "(nil)", 5));
	return (ft_printstr("0x") + ft_printxnbr(ullnbr, "0123456789abcdef"));
}
