/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcb_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:23:16 by gcros             #+#    #+#             */
/*   Updated: 2024/10/15 20:30:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_manip.h"
#include <malloc.h>
#include "mem.h"

void	rcb_destroy(t_rc_buf_p rcb)
{
	free(rcb->buf);
	rcb->buf = NULL;
}
