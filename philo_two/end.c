/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:12:10 by ceccentr          #+#    #+#             */
/*   Updated: 2020/11/25 11:32:46 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void			destroy_mutex(t_table *table)
{
	sem_unlink("/fork");
	sem_close(table->fork);
	sem_unlink("/work");
	sem_close(table->work);
}
