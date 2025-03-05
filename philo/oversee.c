/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oversee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-20 15:06:03 by cgil              #+#    #+#             */
/*   Updated: 2025-02-20 15:06:03 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	one_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->ate_max))
		return (false);
	elapsed = get_time(MILISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	t_to_die = philo->data->time_to_die / 1000;
	if (elapsed > t_to_die)
		return (true);
	return (false);
}

void	*oversee_dinner(void *data)
{
	t_data	*table;
	int		i;

	table = (t_data *)data;
	while (!active_threads(&table->data_mutex, &table->n_running_threads,
			table->n_philos))
			;
	while (!end_simulation(table))
	{
		i = -1;
		while (++i < table->n_philos)
		{
			if (one_died(&table->philos[i]))
			{
				set_bool(&table->data_mutex, &table->end_dinner, true);
				print_status(DEAD, &table->philos[i]);
				break ;
			}
		}
	}
	return (NULL);
}
