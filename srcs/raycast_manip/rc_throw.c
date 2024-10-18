/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_throw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:37:55 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 18:46:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define M_PI 3.14159
#define M_PI_2 1.57079
#include "mlx_manip.h"
#include "struct.h"
#include "raycast_manip.h"
#include "texture_manip.h"
#include "math.h"
#include "libft.h"

// static t_rc_event	v(t_map_p map, t_raycast ray, t_img_descriptor_p id);
// static t_rc_event	h(t_map_p map, t_raycast ray, t_img_descriptor_p id);

t_rc_event	rc_throw(t_map_p map, t_raycast ray, t_img_descriptor_p id)
{
	(void) map, (void) ray, (void) id;
	return ((t_rc_event){.img = tm_get_texture(id, id_texture_e),
		.collision = {0, 0}, .dist = ray.start.y, .offset = ray.start.x / 100});
}

// static t_rc_event	v(t_map_p map, t_raycast ray, t_img_descriptor_p id)
// {
// 	const double	ntan = -tan(ray.angle);
// 	t_vec2			dp;
// 	t_vec2			pos;

// 	if (ray.angle > M_PI_2 && ray.angle < M_PI_2 * 3)
// 	{
// 		pos.x = floorl(ray.start.x);
// 		pos.y = ft_get_real(ray.start.x) * ntan + ray.start.y;
// 		dp = (t_vec2){.x = -1, .y = -ntan};
// 	}
// 	else if (ray.angle < M_PI_2 || ray.angle > M_PI_2 * 3)
// 	{
// 		pos.x = floorl(ray.start.x) + 1;
// 		pos.y = ft_get_real(ray.start.x - 1) * ntan + ray.start.y;
// 		dp = (t_vec2){.x = 1, .y = -ntan};
// 	}
// 	else
// 	{
// 		pos = ray.start;
// 		dp.x = 1;
// 		dp.y = 0;
// 	}
// 	return (a());
// }

// static t_rc_event	h(t_map_p map, t_raycast ray, t_img_descriptor_p id)
// {
// 	const double	atan = -1 / tan(ray.angle);
// 	t_vec2			dp;
// 	t_vec2			pos;

// 	if (ray.angle > M_PI)
// 	{
// 		pos.y = floorl(ray.start.y);
// 		pos.x = ft_get_real(ray.start.y) * atan + ray.start.x;
// 		dp = (t_vec2){.y = -1, .x = -atan};
// 	}
// 	else if (ray.angle < M_PI)
// 	{
// 		pos.y = floorl(ray.start.y) + 1;
// 		pos.x = ft_get_real(ray.start.y - 1) * atan + ray.start.x;
// 		dp = (t_vec2){.y = 1, .x = -atan};
// 	}
// 	else
// 	{
// 		pos = ray.start;
// 		dp.x = 1;
// 		dp.y = 0;
// 	}
// 	return (a());
// }