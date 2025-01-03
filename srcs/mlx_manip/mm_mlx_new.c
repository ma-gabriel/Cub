/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_mlx_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:47:25 by gcros             #+#    #+#             */
/*   Updated: 2024/10/28 21:21:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "put.h"
#include "mlx_manip.h"
#include "defines.h"

t_mlx_p	mm_mlx_new(void)
{
	t_mlx_p	mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		ft_putendl_fd(ERR"mm_mlx_new: mlx_init: NULL pointer returned", 2);
	return (mlx);
}
