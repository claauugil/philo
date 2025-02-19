/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:03:53 by cgil              #+#    #+#             */
/*   Updated: 2025/02/19 17:32:41 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// need to wait for each to end
// have an endless loop

void	*start_dinner(void *info) // dinner simulation
{
	t_philo	*philo;

	philo = (t_philo *)info;
	wait_for_threads(philo->data);
	// set last meal time
	while (!end_simulation(philo->data)) // until the dinner isnt finished
	{
		// check if full 
		if (philo->ate_max)
			break;
		eat(philo);
		//sleep(philo);
		//think(philo);
		//print_status
	}
}

void	prep_dinner(t_data *table) // dinner_start
{
	int	i;

	i = -1;
	if (table-> must_eat == 0) // si ya alcanzo el max_num de comidas
		return ;
	else if (table->n_philos == 1)
		return ;
	else // se inicializa cada hilo
	{
		while (++i < table->n_philos) // crea los hilos == philo_num
			thread_handle(&table->philos[i].thread_id, start_dinner,
				&table->philos[i], CREATE);
	}
	//if all threads ready, dinner begins
	table->start_dinner = get_time(MILISECOND);
	set_bool(&table->data_mutex, &table->prepared_threads, true);
	//wait 
	while (++i < table->n_philos)
		thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
	// if here philos == full
	
	
}
