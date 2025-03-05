/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-24 14:31:17 by cgil              #+#    #+#             */
/*   Updated: 2025-02-24 14:31:17 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_dinner(t_data *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->n_philos)
	{
		philo = table->philos + i;
		mutex_handle(&philo->philo_mutex, DESTROY);
	}
	mutex_handle(&table->print_mutex, DESTROY);
	mutex_handle(&table->data_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}
