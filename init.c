/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:02:32 by cgil              #+#    #+#             */
/*   Updated: 2025/02/19 17:54:04 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	set_forks(t_philo *philos, t_fork *forks, int where_in_table_p)
{
	int	p_nbr;

	p_nbr = philos->data->n_philos;
	if (philos->id % 2 == 0) // pares
	{
		philos->fst_fork = &forks[where_in_table_p]; // espera un puntero
		philos->scnd_fork = &forks[(where_in_table_p + 1) % p_nbr];
	}
	else
	{
		philos->scnd_fork = &forks[where_in_table_p];
		philos->fst_fork = &forks[(where_in_table_p + 1) % p_nbr];
	}
}

static void	init_philos(t_data *table)
{
	int		philo_pos;
	t_philo	*philo;

	philo_pos = -1;
	while (++philo_pos < table->n_philos)
	{
		philo = &table->philos[philo_pos]; // asigna la direccion de memoria del filosofo i dentro del array
		philo->id = philo_pos + 1; // inicializa en 1
		philo->ate_max = false;
		philo->nbr_meals = 0;
		philo->data = table;
		mutex_handle(&philo->philo_mutex, INIT);
		set_forks(philo, table->forks, philo_pos); // no & porque philo ya apunta al ultimo filosofo aisgnado en el bucle
	}
}

void	init_data(t_data *table)
{
	int	i;

	i = -1;
	table->end_dinner = false;
	table->prepared_threads = false;
	table->prepared_threads = 0;
	table->philos = controled_malloc(sizeof(t_philo) * table->n_philos); // asigna memoria para filos
	mutex_handle(&table->data_mutex, INIT);
	mutex_handle(&table->print_mutex, INIT);
	table->forks = controled_malloc(sizeof(t_fork) * table->n_philos); // asigna memoria para forks
	while (++i < table->n_philos) // incializa los forks
	{
		mutex_handle(&table->forks[i].fork, INIT); // acceder al fork que quiero
		table->forks[i].fork_id = i;
	}
	//inicializa filosofos
	init_philos(table);
}
