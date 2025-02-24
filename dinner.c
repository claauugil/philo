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

void	*only_philo(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	wait_for_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time, MILISECOND);
	increase_long(&philo->data->data_mutex, &philo->data->n_running_threads);
	print_status(TAKING_FIRST_FORK, philo);
	while (!end_simulation(philo->data))
		usleep(200);
	return (NULL);
}

void	*start_dinner(void *data) // dinner simulation
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_for_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->n_running_threads);
	anti_starving(philo);
	while (!end_simulation(philo->data)) // until the dinner isnt finished
	{
		if (philo->ate_max)
			break ;
		eat(philo);
		print_status(SLEEPING, philo);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		thinking(philo, false);
	}
	return (NULL);
}

void	prep_dinner(t_data *table) // dinner_start
{
	int	i;

	i = -1;
	if (table-> must_eat == 0) // si ya alcanzo el max_num de comidas
		return ;
	else if (table->n_philos == 1)
		thread_handle(&table->philos[0].thread_id,
			only_philo, &table->philos[0], CREATE);
	else // se inicializa cada hilo
	{
		while (++i < table->n_philos) // crea los hilos == philo_num
			thread_handle(&table->philos[i].thread_id, start_dinner,
				&table->philos[i], CREATE);
	}
	thread_handle(&table->overseeing, oversee_dinner, table, CREATE);
	table->start_dinner = get_time(MILISECOND);
	set_bool(&table->data_mutex, &table->prepared_threads, true);
	i = -1;
	while (++i < table->n_philos)
		thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&table->data_mutex, &table->end_dinner, true); // all have eaten
	thread_handle(&table->overseeing, NULL, NULL, JOIN);
}
