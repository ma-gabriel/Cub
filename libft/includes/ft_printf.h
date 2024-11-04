/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:39:41 by gcros             #+#    #+#             */
/*   Updated: 2023/12/14 06:27:17 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
size_t	ft_printchar(int c);
size_t	ft_printstr(char *str);
size_t	ft_printnbr(long long lnbr);
size_t	ft_printxnbr(unsigned long long lnbr, char *xset);
size_t	ft_printptr(unsigned long long llnbr);

#endif