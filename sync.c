/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:28:32 by claudia           #+#    #+#             */
/*   Updated: 2025/02/19 16:32:09 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_for_threads(t_data *table)
{	// every filo should wait until all threads are ready
	while (!get_bool(&table->data_mutex, &table->prepared_threads));
}