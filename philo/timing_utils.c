/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:56:34 by cgil              #+#    #+#             */
/*   Updated: 2025/03/05 13:19:47 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(t_time_code time_code)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (time_code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1000000));
	else if (time_code == MILISECOND)
		return ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
	else if (time_code == MICROSECOND)
		return (tv.tv_sec * 1000000 + tv.tv_usec);
	return (0);
}

void	ft_usleep(long usec, t_data *table)
{
	long	begin;
	long	elapsed;
	long	left;

	begin = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - begin < usec)
	{
		if (end_simulation(table))
			break ;
		elapsed = get_time(MICROSECOND) - begin;
		left = usec - elapsed;
		if (left > 1000)
			usleep(left / 2);
		else
		{
			while (get_time(MICROSECOND) - begin < usec)
				;
		}
	}
}

/*void	balanced_dinning(t_philo *philo)
{
	if (philo->data->n_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(30000, philo->data);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}*/
