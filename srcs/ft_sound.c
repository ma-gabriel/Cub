/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sound.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:54:14 by gcros             #+#    #+#             */
/*   Updated: 2024/10/15 20:45:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "put.h"
#include "ft_sound.h"
#include "unistd.h"
#include "fcntl.h"

void	ft_sound(int tone)
{
	(void) tone;
	ft_putchar_fd('\a', 1);
}
