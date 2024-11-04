/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:51:40 by gcros             #+#    #+#             */
/*   Updated: 2024/09/17 12:51:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_H
# define NUM_H

# include <limits.h>
# include "str.h"

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
double	ft_maxf(double n1, double n2);
double	ft_minf(double n1, double n2);
double	ft_absf(double n);
int		ft_abs(int n);
int		ft_min(int n1, int n2);
int		ft_max(int n1, int n2);

#endif