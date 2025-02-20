/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:20:08 by claudia           #+#    #+#             */
/*   Updated: 2025/02/18 18:14:55 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_bool(t_mutex *mutex, bool *dest, bool value)
{
	mutex_handle(mutex, LOCK);
	*dest = value; // modificar valor
	mutex_handle(mutex, UNLOCK);
}

bool	get_bool(t_mutex *mutex, bool *value)
{
	bool	done;

	mutex_handle(mutex, LOCK);
	done = *value; // obtener valor
	mutex_handle(mutex, UNLOCK);
	return (done);
}

void	set_long(t_mutex *mutex, long *dest, long value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

long	get_long(t_mutex *mutex, long *value)
{
	long	done;

	mutex_handle(mutex, LOCK);
	done = *value;
	mutex_handle(mutex, UNLOCK);
	return (done);
}

bool	end_simulation(t_data *table)
{
	return (get_bool(&table->data_mutex, &table->end_dinner));
}
