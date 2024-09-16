/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_get_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:31:17 by gcros             #+#    #+#             */
/*   Updated: 2024/09/16 16:57:10 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kb_event.h"

char	kb_get_event(t_kb_event_p kbe, int kc)
{
	if (kc == KB_ESC)
		return (kbe->esc);
	else if (kc >= 'a' && kc <= 'z')
		return (kbe->kb_key[kc - 'a']);
	else if (kc >= '0' && kc <= '9')
		return (kbe->kb_num[kc - '0']);
	else if (kc >= KB_LEFT && kc <= KB_DOWN)
		return (kbe->arrow[kc - KB_LEFT]);
	return (0);
}
