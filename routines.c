/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-20 11:26:59 by cgil              #+#    #+#             */
/*   Updated: 2025-02-20 11:26:59 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *philo)
{
	print_status(THINKING, philo);
}

void	eat(t_philo *philo)
{
	mutex_handle(&philo->fst_fork->fork, LOCK);
	print_status(TAKING_FIRST_FORK, philo);
	mutex_handle(&philo->scnd_fork->fork, LOCK);
	print_status(TAKING_SECOND_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILISECOND));
	philo->nbr_meals++;
	print_status(EATING, philo);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->must_eat > 0 && philo->nbr_meals == philo->data->must_eat)
		set_bool(&philo->philo_mutex, &philo->ate_max, true);
	mutex_handle(&philo->fst_fork->fork, UNLOCK);
	mutex_handle(&philo->scnd_fork->fork, UNLOCK);
}
