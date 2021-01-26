/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:13:30 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/30 11:44:56 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		parse_error(int flag, t_arg *arg)
{
	if (flag == 1)
		arg->error = "Invalid number of arguments.";
	if (flag == 2)
		arg->error = "Invalid number of philosophers.";
	if (flag == 3)
		arg->error = "Incorrect time";
	if (flag == 4)
		arg->error = "Incorrect number of times each philosopher must eat";
	return (0);
}

int		parse_arguments(int argc, char **argv, t_arg *arguments)
{
	if (argc < 5 || argc > 6)
		return (parse_error(1, arguments));
	arguments->nbr_of_philo = ft_atoi(argv[1]);
	if (arguments->nbr_of_philo <= 1 || arguments->nbr_of_philo > MAX_PHILO)
		return (parse_error(2, arguments));
	if ((arguments->time_to_die = ft_atoi(argv[2])) <= 0)
		return (parse_error(3, arguments));
	if ((arguments->time_to_eat = ft_atoi(argv[3])) <= 0)
		return (parse_error(3, arguments));
	if ((arguments->time_to_sleep = ft_atoi(argv[4])) <= 0)
		return (parse_error(3, arguments));
	if (argc == 6)
	{
		arguments->have_six_arg = 1;
		if ((arguments->nbr_must_eat = ft_atoi(argv[5])) <= 0)
			return (parse_error(4, arguments));
	}
	else
		arguments->have_six_arg = 0;
	return (1);
}
