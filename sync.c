/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:28:32 by claudia           #+#    #+#             */
/*   Updated: 2025/02/19 16:32:09 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_for_threads(t_data *table)
{
	while (!get_bool(&table->data_mutex, &table->prepared_threads))
		;
}
//verify that all threads are running

bool	active_threads(t_mutex *mutex, long *threads, long n_philos)
{
	bool	done;

	done = false;
	mutex_handle(mutex, LOCK);
	if (*threads == n_philos)
		done =  true;
	mutex_handle(mutex, UNLOCK);
	return (done);
}

void	increase_long(t_mutex *mutex, long *value)
{
	mutex_handle(mutex, LOCK);
	(*value)++;
	mutex_handle(mutex, UNLOCK);
}
