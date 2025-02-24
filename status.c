/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-20 10:47:11 by cgil              #+#    #+#             */
/*   Updated: 2025-02-20 10:47:11 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILISECOND) - philo->data->start_dinner ;
	if (philo->ate_max)
		return ;
	mutex_handle(&philo->data->print_mutex, LOCK);
	if ((status == TAKING_FIRST_FORK || status == TAKING_SECOND_FORK)
		&& !end_simulation(philo->data))
		printf("\033[38;2;126;161;239m%ld %d has taken a fork\033[0m\n",
			elapsed, philo->id);
	else if (status == EATING && !end_simulation(philo->data))
		printf("\033[38;2;245;166;221m%ld %d is eating\033[0m\n", elapsed,
			philo->id);
	else if (status == THINKING && !end_simulation(philo->data))
		printf("\033[38;2;126;161;239m%ld %d is thinking\033[0m\n", elapsed,
			philo->id);
	else if (status == SLEEPING && !end_simulation(philo->data))
		printf("\033[38;2;126;161;239m%ld %d is sleeping\033[0m\n", elapsed,
			philo->id);
	else if (status == DEAD)
		printf("\033[38;2;226;105;115m%ld %d died 😵\033[0m\n", elapsed,
			philo->id);
	mutex_handle(&philo->data->print_mutex, UNLOCK);
}
