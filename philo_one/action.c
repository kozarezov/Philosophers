/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:07:38 by ceccentr          #+#    #+#             */
/*   Updated: 2020/12/01 15:01:08 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void			print_act(int time, int num, char *str, t_table *table)
{
	char		*time_s;
	char		*num_s;
	char		*print;
	char		*buf;

	pthread_mutex_lock(&(table->work));
	if (table->is_dead == 1)
	{
		time_s = ft_itoa(time);
		num_s = ft_itoa(num);
		buf = ft_strjoin(time_s, " ");
		free(time_s);
		print = ft_strjoin(buf, num_s);
		free(buf);
		free(num_s);
		buf = ft_strjoin(" ", print);
		free(print);
		print = ft_strjoin(buf, str);
		ft_putstr_fd(print, 1);
		free(buf);
		free(print);
	}
	pthread_mutex_unlock(&(table->work));
}

void			fork_lock(t_table *table, t_philo *philo, t_func *arg, int flag)
{
	if (flag == 1)
	{
		print_act(ft_dead(philo, arg), philo->id, " has taken a fork\n", table);
		pthread_mutex_lock(&(table->forks[philo->left_fork]));
		print_act(ft_dead(philo, arg), philo->id, " has taken a fork\n", table);
		pthread_mutex_lock(&table->forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_unlock(&table->forks[philo->right_fork]);
		pthread_mutex_unlock(&table->forks[philo->left_fork]);
	}
}

void			*action(void *function)
{
	t_func		*arg;
	t_philo		*philo;
	t_table		*table;
	int			i;

	arg = (t_func*)function;
	philo = arg->philo;
	table = arg->table;
	i = 0;
	while (table->is_dead)
	{
		fork_lock(table, philo, arg, 1);
		print_act(ft_dead(philo, arg), philo->id, " is eating\n", table);
		gettimeofday(&(philo->last_eat), NULL);
		my_usleep(arg->arg->time_to_eat);
		fork_lock(table, philo, arg, 0);
		i++;
		if (arg->arg->have_six_arg && arg->arg->nbr_must_eat == i)
			break ;
		print_act(ft_dead(philo, arg), philo->id, " is sleeping\n", table);
		my_usleep(arg->arg->time_to_sleep);
		print_act(ft_dead(philo, arg), philo->id, " is thinking\n", table);
	}
	return (NULL);
}
