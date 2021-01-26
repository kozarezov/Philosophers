/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:12:10 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/09 10:22:46 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void			destroy_mutex(t_arg *arguments, t_table *table)
{
	int			i;

	i = 0;
	pthread_mutex_destroy(&(table->work));
	while (i < arguments->nbr_of_philo)
	{
		pthread_mutex_destroy(&(table->forks[i]));
		i++;
	}
}
