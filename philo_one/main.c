/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:35:45 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/25 10:59:57 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int				main(int argc, char **argv)
{
	t_arg		g_arg;
	t_func		function[MAX_PHILO];
	int			i;

	i = 0;
	if (!(parse_arguments(argc, argv, &g_arg)))
		return (error_arguments(g_arg.error));
	init_all(&g_arg, function);
	return (0);
}
