/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 03:00:40 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/22 03:00:42 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	take_fokrs(t_philo *philo)
{
	sem_wait(philo->all->forks);
	print_message("has taken a fork", philo);
	sem_wait(philo->all->forks);
	print_message("has taken a fork", philo);
}

void	put_forks_sleep(t_philo *philo)
{
	sem_post(philo->all->forks);
	sem_post(philo->all->forks);
	print_message("is sleeping", philo);
	usleep(philo->all->time_to_sleep * 1000);
}

void	*life_cycle(void *philosopher)
{
	u_int64_t	time;
	t_philo		*philo;

	philo = philosopher;
	while (1)
	{
		take_fokrs(philo);
		sem_wait(philo->eating);
		philo->last_eating = get_time_ms();
		philo->die_time = philo->last_eating + philo->all->time_to_die;
		print_message("is eating", philo);
		time = get_time_ms();
		while (get_time_ms() - time < philo->all->time_to_eat)
			if (philo->is_dead == 1)
			{
				sem_post(philo->eating);
				exit(0);
			}
		philo->eat_count++;
		sem_post(philo->eating);
		put_forks_sleep(philo);
		print_message("is thinking", philo);
	}
}

void	*philo_process(t_philo *philo)
{
	int			is_feed;
	pthread_t	pthread;

	pthread_create(&pthread, NULL, &life_cycle, philo);
	pthread_detach(pthread);
	is_feed = 0;
	while (1)
	{
		if (get_time_ms() > philo->die_time)
		{
			philo->is_dead = 1;
			sem_wait(philo->eating);
			sem_wait(philo->all->writing);
			printf("%lu %i died\n",
				(unsigned long)(get_time_ms() - philo->all->start_time),
				philo->i + 1);
			sem_post(philo->all->die);
			exit(0);
		}
		if (!is_feed && philo->eat_count >= philo->all->number_times_to_eat)
		{
			is_feed = 1;
			sem_post(philo->all->how_much_feed_up);
		}
	}
}
