/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:31:17 by ceccentr          #+#    #+#             */
/*   Updated: 2020/12/01 15:09:51 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char				*name_thread(int n)
{
	char			*temp;
	char			*buf;

	buf = ft_itoa(n - 1);
	temp = ft_strjoin("eating_", buf);
	free(buf);
	return (temp);
}

void				start_thread(int n)
{
	pthread_t		tid;
	struct timeval	now;
	char			*temp;

	temp = name_thread(n);
	sem_unlink(temp);
	g_eating = sem_open(temp, O_CREAT, S_IRWXU, 1);
	free(temp);
	pthread_create(&tid, NULL, action, &n);
	gettimeofday(&g_last_eat, NULL);
	while (1)
	{
		sem_wait(g_eating);
		gettimeofday(&now, NULL);
		if (ft_dead(now, g_last_eat) > g_arg.time_to_die)
		{
			g_arg.is_dead = 0;
			print_act(ft_dead(now, g_arg.start_time), n, " dies\n\0");
			sem_post(g_eating);
			sem_post(g_dead);
			return ;
		}
		sem_post(g_eating);
		my_usleep(5);
	}
}

int					*create_child(int n)
{
	int				*pids;
	int				i;

	if ((pids = malloc(sizeof(int) * n)) == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			start_thread(i + 1);
			return (NULL);
		}
		i++;
	}
	return (pids);
}

void				*count_eat(void *arg)
{
	int				i;

	(void)arg;
	i = 0;
	while (i < g_arg.nbr_of_philo)
	{
		sem_wait(g_count);
		i++;
	}
	sem_post(g_dead);
	return (NULL);
}

void				init_all(t_arg *arguments)
{
	int				*pids;
	pthread_t		tid;
	int				i;

	i = -1;
	exit_sim();
	g_forks = sem_open("/fork", O_CREAT, S_IRWXU, arguments->nbr_of_philo);
	g_dead = sem_open("/dead", O_CREAT, S_IRWXU, 0);
	g_count = sem_open("/count", O_CREAT, S_IRWXU, 0);
	g_print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	gettimeofday(&arguments->start_time, NULL);
	if (arguments->have_six_arg)
		pthread_create(&tid, NULL, count_eat, NULL);
	if ((pids = create_child(arguments->nbr_of_philo)) == NULL)
	{
		exit_sim();
		exit(EXIT_FAILURE);
	}
	sem_wait(g_dead);
	usleep(100);
	while (++i < arguments->nbr_of_philo)
		kill(pids[i], SIGKILL);
	free(pids);
}
