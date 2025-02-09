/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 10:28:39 by cgil              #+#    #+#             */
/*   Updated: 2025-02-06 10:28:39 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int ac, char *av[])
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		print_err("Incorrect input\n"
			"Run as: number_of_philosophers time_to_die time_to_eat time_to_sleep\
				[number_of_times_each_philosopher_must_eat]");
	}
	else
	{
		//error checking and filling table
		parse_input(&data, av);
		//ini & malloc philos and forks
		init_data(&data);
		//starting the dinner
		setting_table(&data);
		//clean table (freeing to avoid leaks)
		tidy_table(&data);
	}
}
