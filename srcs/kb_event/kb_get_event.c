/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_get_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:31:17 by gcros             #+#    #+#             */
/*   Updated: 2024/10/30 14:28:11 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kb_event.h"

char	kb_get_event(t_kb_event_p kbe, int kc)
{
	if (kc == KB_ESC)
		return (kbe->esc);
	else if (kc == KB_TAB)
		return (kbe->tab);
	else if (kc >= 'a' && kc <= 'z')
		return (kbe->kb_key[kc - 'a']);
	else if (kc >= '0' && kc <= '9')
		return (kbe->kb_num[kc - '0']);
	else if (kc >= KB_LEFT && kc <= KB_DOWN)
		return (kbe->arrow[kc - KB_LEFT]);
	else if (kc == KB_SPACE)
		return (kbe->space);
	else if (kc == KB_LCTRL || kc == KB_RCTRL)
		return (kbe->ctrl);
	else if (kc == MOUSE1 || kc == MOUSE2 || kc == MOUSE3)
		return (kbe->mouse[-kc - 1]);
	return (0);
}
