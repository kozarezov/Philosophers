/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:31:17 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/30 11:44:36 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void			init_philo(t_arg *arguments, t_philo *philo)
{
	int			i;

	i = 0;
	gettimeofday(&arguments->start_time, NULL);
	while (i < arguments->nbr_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].last_eat = arguments->start_time;
		i++;
	}
}

int				init_table(t_arg *arguments, t_table *table)
{
	table->is_dead = 1;
	sem_unlink("/fork");
	table->fork = sem_open("/fork", O_CREAT | O_EXCL, \
		0644, arguments->nbr_of_philo);
	sem_unlink("/work");
	table->work = sem_open("/work", O_CREAT | O_EXCL, 0644, 1);
	return (1);
}

void			start_thread(t_arg *arg, t_func *function, pthread_t *threads)
{
	int			i;

	i = 0;
	while (i < arg->nbr_of_philo)
	{
		pthread_create(&threads[i], NULL, action, &function[i]);
		usleep(5);
		i++;
	}
}

void			wait_thread(t_arg *arg, pthread_t *threads)
{
	int			i;

	i = 0;
	while (i < arg->nbr_of_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void			init_all(t_arg *arguments, t_func *function)
{
	pthread_t	threads[MAX_PHILO];
	t_philo		philo[MAX_PHILO];
	t_table		table;
	int			i;

	i = 0;
	init_philo(arguments, philo);
	if (!(init_table(arguments, &table)))
		return ;
	while (i < arguments->nbr_of_philo)
	{
		function[i].arg = arguments;
		function[i].philo = &philo[i];
		function[i].table = &table;
		function[i].threads = &threads[i];
		i++;
	}
	start_thread(arguments, function, threads);
	wait_thread(arguments, threads);
	destroy_mutex(&table);
}
