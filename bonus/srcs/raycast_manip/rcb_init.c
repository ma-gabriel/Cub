/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcb_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:08:21 by gcros             #+#    #+#             */
/*   Updated: 2024/10/18 15:57:57 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "mem.h"
#include "raycast_manip.h"

int	rcb_init(t_rc_buf_p rcb, size_t size)
{
	rcb->buf = malloc(size * sizeof(*rcb->buf));
	if (rcb->buf == NULL)
		return (1);
	ft_bzero(rcb->buf, size * sizeof(*rcb->buf));
	rcb->size = size;
	return (0);
}
