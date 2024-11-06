/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:08:27 by gcros             #+#    #+#             */
/*   Updated: 2024/09/17 12:51:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_absf(double n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}