/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:14:33 by gcros             #+#    #+#             */
/*   Updated: 2024/09/26 22:38:15 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "arr.h"
# include "char.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "list.h"
# include "mem.h"
# include "num.h"
# include "put.h"
# include "arr.h"
# include "vector.h"

void	ft_memswap(void *p1, void *p2, size_t len);
void	ft_memswapbyte(void *p1, void *p2, size_t len);
double	ft_get_real(double n);

#endif
