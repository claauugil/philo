/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-07 12:02:32 by cgil              #+#    #+#             */
/*   Updated: 2025-02-07 12:02:32 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void	set_forks(t_philo *philos, t_fork *forks, int where_in_table)
{
	int	p_nbr;

	p_nbr =  philos->data->n_philos;

	philos->right_fork = &forks[where_in_table];
}

static void	init_philos(t_data *table)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while(++i < table->n_philos)
	{
		philo = &table->philos[i]; // asigna la direccion de memoria del filosofo i dentro del array
		philo->id = i + 1; // inicializa en 1
		philo->ate_max = false;
		philo->nbr_meals = 0;
		philo-> data = table;
	}
	set_forks(philo, table->forks, i); // i es la posicion en la mesa
}

void	init_data(t_data *table)
{
	int	i;

	i = -1;
	table->end_dinner = false;
	table->philos = controled_malloc(sizeof(t_philo) * table->n_philos); // asigna memoria para filos
	table->forks = controled_malloc(sizeof(t_fork) * table->n_philos); // asigna memoria para forks
	while (++i < table->n_philos) // incializa los forks
	{
		mutex_handle(&table->forks[i].fork, INIT); // acceder al fork que quiero
		table->forks[i].fork_id = i;
	}
	//inicializa filosofos
	init_philos(&table);
}
