/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:28:39 by cgil              #+#    #+#             */
/*   Updated: 2025/02/19 16:26:03 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Run as: number_of_philosophers time_to_die time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]");
		return (-1);
	}
	else
	{
		if (parse_input(&data, av) == -2)
			return (-1);
		init_data(&data);
		prep_dinner(&data);
		//clean table (freeing to avoid leaks)
		//tidy_table(&data);
	}
}
