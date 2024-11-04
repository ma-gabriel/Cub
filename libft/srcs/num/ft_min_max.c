/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:22:01 by gcros             #+#    #+#             */
/*   Updated: 2024/09/17 12:51:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_minf(double n1, double n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

double	ft_maxf(double n1, double n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
