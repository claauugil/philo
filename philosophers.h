/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 16:22:34 by cgil              #+#    #+#             */
/*   Updated: 2025-02-05 16:22:34 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h> // mutex, threads
#include <stdbool.h>
#include <sys/time.h> // get time
#include <limits.h> //INT_MAX
#include <errno.h>

//prototipos

//enumeracion de constantes, cada valor representa
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

typedef struct s_data	t_data;
typedef pthread_mutex_t	t_mutex; // acorta el nombre del tipo de dato

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
struct			s_data // table from video
{
	long				n_philos;
	long				time_to_die;
	long				time_to_sleep;
	long				time_to_eat;
	long				must_eat; //optional | -1 means there is no input
	long				start_dinner; // timestamp
	bool				end_dinner; // when one dies or all are full
	bool				prepared_threads; // sincronizar filosofos
	t_mutex				data_mutex; // avoid data  rac es when reading from table
	//t_mutex			write_mutex;
	t_fork				*forks; // array de forks
	t_philo				*philos; // array de filosofos
};

int		parse_input(t_data *data, char *av[]);
void	init_data(t_data *table);
void	*controled_malloc(size_t bytes);
void	mutex_handle(t_mutex *mutex, t_opcode opcode);
void	thread_handle(pthread_t *thread,
			void *(*foo)(void*), void *data, t_opcode opcode);
void	prep_dinner(t_data *table);
void	*start_dinner(void *data);
