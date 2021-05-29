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

#include "philo_two.h"

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

void	*philo_thread(void *philosopher)
{
	t_philo		*philo;
	u_int64_t	time;

	philo = (t_philo *)philosopher;
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
				return (NULL);
			}
		philo->eat_count++;
		sem_post(philo->eating);
		put_forks_sleep(philo);
		if (philo->all->stop_all == 1)
			return (NULL);
		print_message("is thinking", philo);
	}
}
