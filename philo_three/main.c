/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:35:45 by ceccentr          #+#    #+#             */
/*   Updated: 2020/12/01 15:03:26 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int				main(int argc, char **argv)
{
	if (!(parse_arguments(argc, argv, &g_arg)))
		return (error_arguments(g_arg.error));
	g_count_eating = 0;
	g_arg.is_dead = 1;
	init_all(&g_arg);
	exit_sim();
	return (EXIT_SUCCESS);
}
