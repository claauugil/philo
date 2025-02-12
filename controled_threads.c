/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controled_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 11:25:25 by cgil              #+#    #+#             */
/*   Updated: 2025-02-12 11:25:25 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	thread_error(int status, t_opcode opcode)
{
	if (status == 0) // everything is fine
		 return ;
	if (EAGAIN == status)
		print_err("No resources to create another thread");
	else if (EPERM == status)
		print_err("The caller does noot have appropiate permission\n");
	else if (EINVAL == status && opcode == CREATE)
		print_err("The value specified by attr is invalid.");
	else if (EINVAL == status && (opcode == JOIN || opcode == DETACH))
		print_err("The value specified by thread is not joinable.");
	else if (ESRCH == status)
		print_err("No thread could be found corresponding to thatt"
					"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		print_err("A deadlock was detected or the value of"
					"thread specifies the calling thread");
}

void	thread_handle(pthread_t *thread, void *(*foo)(void*), void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		thread_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		thread_error(pthread_detach(*thread), opcode);
	else
		print_err("Wrong opcode for thread_handle: "
			"use <CREATE> <JOIN> <DETACH>");
}
