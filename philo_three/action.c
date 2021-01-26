/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:07:38 by ceccentr          #+#    #+#             */
/*   Updated: 2020/12/01 15:19:14 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void				print_act(int time, int num, char *str)
{
	char			*time_s;
	char			*num_s;
	char			*print;
	char			*buf;

	sem_wait(g_print);
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
	if (g_arg.is_dead == 1)
		sem_post(g_print);
}

void				fork_lock(int flag, int n)
{
	struct timeval	now;

	if (flag == 1)
	{
		gettimeofday(&now, NULL);
		print_act(ft_dead(now, g_arg.start_time), n, " has taken a fork\n\0");
		sem_wait(g_forks);
		gettimeofday(&now, NULL);
		print_act(ft_dead(now, g_arg.start_time), n, " has taken a fork\n\0");
		sem_wait(g_forks);
	}
	else
	{
		sem_post(g_forks);
		sem_post(g_forks);
	}
}

void				*action(void *arg)
{
	int				n;
	struct timeval	now;

	n = *(int*)arg;
	while (g_arg.is_dead)
	{
		fork_lock(1, n);
		gettimeofday(&now, NULL);
		print_act(ft_dead(now, g_arg.start_time), n, " is eating\n\0");
		if (g_arg.have_six_arg && g_arg.nbr_must_eat == ++g_count_eating)
			sem_post(g_count);
		sem_wait(g_eating);
		gettimeofday(&g_last_eat, NULL);
		my_usleep(g_arg.time_to_eat);
		sem_post(g_eating);
		fork_lock(0, n);
		gettimeofday(&now, NULL);
		print_act(ft_dead(now, g_arg.start_time), n, " is sleeping\n\0");
		my_usleep(g_arg.time_to_sleep);
		gettimeofday(&now, NULL);
		print_act(ft_dead(now, g_arg.start_time), n, " is thinking\n\0");
	}
	return (NULL);
}
