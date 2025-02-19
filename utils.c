/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:33:11 by claudia           #+#    #+#             */
/*   Updated: 2025/02/19 18:09:46 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//time_code = seconds, miliseconds and microseconds

long    get_time(t_time_code time_code)
{
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    if (time_code == SECOND)
        return (tv.tv_sec + (tv.tv_usec / 1e6));
    else if (time_code == MILISECOND)
        return ((tv.tv_sec * 1e3) + tv.tv_usec / 1e3);
    else if (time_code == MICROSECOND)
        return (tv.tv_sec * 1e6 + tv.tv_usec);
    return (0);
}

void	precise_usleep(long usec, t_data *table)
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
		if (left > 1e3) // milisecond
			usleep(left / 2);
		else
			while (get_time(MICROSECOND) - begin < usec);
	}
}

void	print_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;
	
	elapsed = get_time(MILISECOND) - philo->data->start_dinner ;
	mutex_handle(&philo->data->print_mutex, LOCK);
	if (status == TAKING_FIRST_FORK || status == TAKING_SECOND_FORK
		&& !end_simulation(philo->data));
			printf("&ld" "%d has taken a fork\n");
	mutex_handle(&philo->data->print_mutex, LOCK);
}