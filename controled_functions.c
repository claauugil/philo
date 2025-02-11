/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controled_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 18:53:54 by cgil              #+#    #+#             */
/*   Updated: 2025-02-11 18:53:54 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*controled_malloc(size_t bytes)
{
	void	*controled;

	controled = malloc(bytes);
	if (controled == NULL)
		print_err("Error while allocating memory with malloc");
	return (controled);
}

// for mutex

static void	mutexes_errors(int status, t_opcode opcode)
{
	if (status == 0) // everything is fine
		return ;
	if (EINVAL == status && (opcode == LOCK || opcode == UNLOCK))
		print_err("The value specified by mutex is invalid.");
	else if (EINVAL == status && opcode == INIT)
		print_err("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		print_err("A deadlock would occur if the thread blocked waiting for mutex");
	else if (EPERM == status)
		print_err("The current thread does not hold a lock on mutex");
	else if (ENOMEM == status)
		print_err("The process cannot allocate enough memory to create another mutex");
	else if (EBUSY == status)
		print_err("Mutex is locked");
}

void	controled_mutexes(t_mutex *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
	else
		print_err("invalid opcode for mutex handle");
}
