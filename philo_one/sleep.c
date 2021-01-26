/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:45:39 by ceccentr          #+#    #+#             */
/*   Updated: 2020/10/25 15:03:07 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long		get_time_in_ms(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void				my_usleep(unsigned int millisec)
{
	unsigned long	start_time;

	start_time = get_time_in_ms();
	while (get_time_in_ms() - start_time < millisec)
		usleep(10);
}
