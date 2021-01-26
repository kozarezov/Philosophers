/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:12:59 by ceccentr          #+#    #+#             */
/*   Updated: 2020/10/25 15:00:11 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		error_arguments(char *str)
{
	ft_putstr_fd(PROG_NAME, STDERR);
	ft_putstr_fd(" - error: ", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd("\n", STDERR);
	return (1);
}
