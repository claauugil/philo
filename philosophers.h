/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:22:34 by cgil              #+#    #+#             */
/*   Updated: 2025/02/19 17:56:10 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h> // get time
#include <limits.h>
#include <errno.h>

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}				t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILISECOND,
	MICROSECOND,
}				t_time_code;

typedef enum e_status
{
	SLEEPING,
	EATING,
	THINKING,
	TAKING_FIRST_FORK,
	TAKING_SECOND_FORK,
	DEAD,
}				t_philo_status;

typedef struct s_data	t_data;
typedef pthread_mutex_t	t_mutex;

typedef struct s_fork
{
	t_mutex	fork;
	int		fork_id;
}				t_fork;

typedef struct s_philo
{
	int					id;
	long				nbr_meals;
	bool				ate_max;
	long				last_meal_time;
	t_fork				*fst_fork;
	t_fork				*scnd_fork;
	pthread_t			thread_id;
	t_mutex				philo_mutex;
	t_data				*data;
}						t_philo;
struct			s_data
{
	long				n_philos;
	long				time_to_die;
	long				time_to_sleep;
	long				time_to_eat;
	long				must_eat;
	long				start_dinner; // timestamp
	bool				end_dinner;
	bool				prepared_threads;
	long				n_running_threads;
	t_mutex				data_mutex;
	t_mutex				print_mutex;
	t_fork				*forks;
	t_philo				*philos;
	pthread_t			overseeing;
};

int		parse_input(t_data *data, char *av[]);
void	init_data(t_data *table);
void	*controled_malloc(size_t bytes);
void	mutex_handle(t_mutex *mutex, t_opcode opcode);
void	thread_handle(pthread_t *thread,
			void *(*foo)(void*), void *data, t_opcode opcode);
void	prep_dinner(t_data *table);
void	*start_dinner(void *data);
void	set_bool(t_mutex *mutex, bool *dest, bool value);
bool	get_bool(t_mutex *mutex, bool *value);
void	set_long(t_mutex *mutex, long *dest, long value);
long	get_long(t_mutex *mutex, long *value);
void	wait_for_threads(t_data *table);
long	get_time(t_time_code time_code);
bool	end_simulation(t_data *table);
void	precise_usleep(long usec, t_data *table);
void	print_status(t_philo_status status, t_philo *philo);
void	thinking(t_philo *philo);
void	eat(t_philo *philo);
bool	active_threads(t_mutex *mutex, long *threads, long n_philos);
void	increase_long(t_mutex *mutex, long *value);
void	*oversee_dinner(void *data);
