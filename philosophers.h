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
# include <stdbool.h>
# include <sys/time.h> // get time
# include <limits.h> //INT_MAX
# include <errno.h>

//prototipos

//enumeracion de constantes, cada valor representa
typedef	enum	e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}				t_opcode;

typedef pthread_mutex_t t_mutex; // acorta el nombre del tipo de dato

typedef struct s_data	t_data;

//tenedores
typedef struct	s_fork
{
	t_mutex	fork;
	int 	fork_id;
}				t_fork;

typedef struct s_philo
{
	int					id;
	long				nbr_meals;
	bool				ate_max;
	long				last_meal_time;
	t_fork				*left_fork;
	t_fork				*_fork;
	pthread_t			thread_id;
	t_mutex				philo_mutex;
	t_data				*data;
}						t_philo;

// table from the video

struct			s_data
{
	long				n_philos;
	long				time_to_die;
	long				time_to_sleep;
	long				time_to_eat;
	long				must_eat; //optional | -1 means there is no input
	long				start_dinner; // timestamp
	bool				end_dinner; // when one dies or all are full
	//bool				all_threads_ready;
	long				threads_running_count;
	//t_mutex				data_mutex;
	//t_mutex				write_mutex;
	t_fork				*forks;
	t_philo				*philos;
	//pthread_t			monitor;
};


void	parse_input(t_data *data, char *av[]);
void	print_err(const char *error);

//void	print_err(const char *error);

