/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:15:21 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/30 17:01:15 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int					ft_dead(struct timeval now, struct timeval last)
{
	unsigned long	time_last;
	unsigned long	time_now;

	time_last = (last.tv_usec / 1000 + last.tv_sec * 1000);
	time_now = (now.tv_usec / 1000 + now.tv_sec * 1000);
	if (time_last >= time_now)
		return (0);
	return (time_now - time_last);
}
