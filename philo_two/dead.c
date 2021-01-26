/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:15:21 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/25 11:32:32 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int					ft_dead(t_philo *philo, t_func *function)
{
	struct timeval	now;
	struct timeval	last;
	unsigned long	time_last;
	unsigned long	time_now;
	unsigned long	time_start;

	gettimeofday(&now, NULL);
	last = function->arg->start_time;
	time_last = (philo->last_eat.tv_usec / \
		1000 + philo->last_eat.tv_sec * 1000);
	time_now = (now.tv_usec / 1000 + now.tv_sec * 1000);
	time_start = (last.tv_usec / 1000 + last.tv_sec * 1000);
	sem_wait(function->table->work);
	if (time_now - time_last > (unsigned long)(function->arg->time_to_die))
	{
		sem_post(function->table->work);
		print_act(time_now - time_start, philo->id, " dies\n", function->table);
		function->table->is_dead = 0;
	}
	sem_post(function->table->work);
	return (time_now - time_start);
}
