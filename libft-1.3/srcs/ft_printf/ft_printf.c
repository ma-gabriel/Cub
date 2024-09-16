/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:05:02 by gcros             #+#    #+#             */
/*   Updated: 2023/12/14 06:27:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_runflag(const char *str, va_list ap)
{
	if (str[1] == 'c')
		return (ft_printchar(va_arg(ap, int)));
	else if (str[1] == 's')
		return (ft_printstr(va_arg(ap, char *)));
	else if (str[1] == 'p')
		return (ft_printptr(va_arg(ap, unsigned long long)));
	else if (str[1] == 'i' || str[1] == 'd')
		return (ft_printnbr(va_arg(ap, int)));
	else if (str[1] == 'u')
		return (ft_printnbr(va_arg(ap, unsigned int)));
	else if (str[1] == 'x')
		return (ft_printxnbr(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (str[1] == 'X')
		return (ft_printxnbr(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (str[1] == '%')
		return (ft_printchar('%'));
	else if (str[1] == '\0')
		return (0);
	return (0);
}

static int	ft_isflag(const char c)
{
	char	*set;

	set = "cspdiuxX%";
	if (c == '\0')
		return (1);
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	wc;
	va_list	ap;

	i = 0;
	wc = 0;
	if (write(1, NULL, 0) || str == NULL)
		return (-1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_isflag(str[i + 1]))
		{
			if (str[i + 1] == '\0')
				return (va_end(ap), -1);
			wc += ft_runflag(str + i, ap);
			i++;
		}
		else
			wc += ft_printchar(str[i]);
		i++;
	}
	return (va_end(ap), wc);
}
