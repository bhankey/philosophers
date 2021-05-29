/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:20:19 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/19 14:20:39 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_PHILO_THREE_H
# define PHILOSOPHERS_PHILO_THREE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <pthread.h>
# include <signal.h>
# include <sys/types.h>

typedef struct timeval	t_timeval;

struct s_all;

typedef struct	s_philo {
	uint				i;
	uint				is_dead;
	uint				eat_count;
	sem_t				*eating;
	u_int64_t			last_eating;
	u_int64_t			die_time;
	struct s_all		*all;
}				t_philo;

typedef struct	s_all {
	int				num_of_philo;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	u_int64_t		time_to_die;
	int64_t			number_times_to_eat;
	int8_t			stop_all;
	sem_t			*forks;
	sem_t			*writing;
	u_int64_t		start_time;
	t_philo			*philos;
	pid_t			*pids;
	sem_t			*how_much_feed_up;
	sem_t			*die;
}				t_all;

/*
 ** time functions
*/

u_int64_t		get_time_from_start_ms(t_all *all);
u_int64_t		get_time_ms(void);

/*
 ** print functions
*/

int				print_error(char *str);
void			print_message(char *message, t_philo *philo);
int				semaphore_failed(void);

/*
 ** clean functions
*/

void			clear_mem(t_all *all);
void			exit_and_free(t_all *all);

/*
 ** fill functions
*/

int				check_args_fill(int argc, char **argv, t_all *all);
int				init_table_philos(t_all *all);

/*
 ** main functions
*/

void			*philo_process(t_philo *philo);
void			*monitor_d();
void			*monitor_c(void *all_info);

/*
 ** utils functions
*/

int				ft_atoi(const char *nptr);
void			ft_itoa_to_print(char *str, char **ptr, unsigned int n);
void			ft_itoa_to_init(char *str, unsigned int n);
void			str_philo_join(char *result, char *philo, int i);

#endif
