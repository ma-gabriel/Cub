/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:51:40 by gcros             #+#    #+#             */
/*   Updated: 2024/03/07 14:25:44 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_H
# define NUM_H

# include <limits.h>
# include "str.h"

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
float	ft_maxf(float n1, float n2);
float	ft_minf(float n1, float n2);
float	ft_absf(float n);
int		ft_abs(int n);
int		ft_min(int n1, int n2);
int		ft_max(int n1, int n2);

#endif