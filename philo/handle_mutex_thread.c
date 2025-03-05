/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mutex_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-28 10:56:03 by cgil              #+#    #+#             */
/*   Updated: 2025-02-28 10:56:03 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*controled_malloc(size_t bytes)
{
	void	*controled;

	controled = malloc(bytes);
	if (controled == NULL)
	{
		printf("Error while allocating memory with malloc");
		return (NULL);
	}
	return (controled);
}

void	mutex_handle(t_mutex *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mutex);
	else if (opcode == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (opcode == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (opcode == DESTROY)
		pthread_mutex_destroy(mutex);
}

void	thread_handle(pthread_t *thread,
			void *(*foo)(void*), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		pthread_create(thread, NULL, foo, data);
	else if (opcode == JOIN)
		pthread_join(*thread, NULL);
}
