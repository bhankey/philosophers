/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:20:19 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/19 14:20:39 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_PHILO_ONE_H
# define PHILOSOPHERS_PHILO_ONE_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

struct s_all;

typedef struct	s_philo {
	u_int64_t			i;
	u_int64_t			is_dead;
	u_int64_t			left_fork;
	u_int64_t			right_fork;
	u_int64_t			eat_count;
	pthread_mutex_t		eating;
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
	int				stop_all;
	pthread_mutex_t	*forks;
	pthread_mutex_t writing;
	u_int64_t		start_time;
	t_philo			*philos;
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

/*
 ** clean functions
*/

void			clear_mem(t_all *all);

/*
 ** fill functions
*/

int				check_args_fill(int argc, char **argv, t_all *all);
void			init_table_philos(t_all *all);

/*
 ** main functions
*/

void			*philo_thread(void *philo);
void			*monitor_d(void *all_info);
void			*monitor_c(void *all_info);

/*
 ** utils functions
*/

int				ft_atoi(const char *nptr);
void			ft_itoa_to_print(char *str, char **ptr, unsigned int n);

#endif
