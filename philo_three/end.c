/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:12:10 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/25 13:51:10 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void			exit_sim(void)
{
	int			i;
	char		*temp;

	i = 0;
	while (i < g_arg.nbr_of_philo)
	{
		temp = name_thread(i);
		sem_unlink(temp);
		sem_close(g_eating);
		free(temp);
		i++;
	}
	sem_unlink("/fork");
	sem_close(g_forks);
	sem_unlink("/dead");
	sem_close(g_dead);
	sem_unlink("/print");
	sem_close(g_print);
}
