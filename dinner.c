/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-18 10:03:53 by cgil              #+#    #+#             */
/*   Updated: 2025-02-18 10:03:53 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// need to wait for each to end
// have an endless loop

void	*start_dinner(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_for_threads(philos->data);
	return (NULL);
}

void	prep_dinner(t_data *table)
{
	int	i;

	i =  -1;
	if (table-> must_eat == 0) // si ya alcanzo el max_num de comidas
		return ;
	else if (table->n_philos == 1)
		return ; // fix
	else  // se inicializa cada hilo
	{
		while (++i < table->n_philos) // crea los hilos == philo_num
			thread_handle(&table->philos[i].thread_id, start_dinner,
				&table->philos[i], CREATE);
	}
}
