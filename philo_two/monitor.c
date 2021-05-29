/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:25:02 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/22 03:03:09 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		monitoring_death(t_all *all)
{
	int i;

	i = -1;
	while (++i < all->num_of_philo)
	{
		if (get_time_ms() > all->philos[i].die_time)
		{
			if (all->stop_all == 1)
				return (1);
			all->philos->is_dead = 1;
			sem_wait(all->philos[i].eating);
			sem_wait(all->writing);
			printf("%lu %i died\n",
				(unsigned long)(get_time_ms() - all->start_time),
					i + 1);
			return (1);
		}
	}
	return (0);
}

int		monitoring_count(t_all *all)
{
	int i;
	int is_all_eat;

	i = -1;
	is_all_eat = 1;
	while (is_all_eat && ++i < all->num_of_philo)
		if (all->philos[i].eat_count < all->number_times_to_eat)
		{
			is_all_eat = 0;
		}
	if (is_all_eat == 1)
	{
		if (all->stop_all == 1)
			return (1);
		sem_wait(all->writing);
		printf("all was feed up\n");
	}
	return (is_all_eat);
}

void	*monitor_d(void *all_info)
{
	t_all	*all;

	all = (t_all *)all_info;
	while (1)
		if (all->stop_all == 1 || monitoring_death(all) == 1)
		{
			all->stop_all = 1;
			return (NULL);
		}
}

void	*monitor_c(void *all_info)
{
	t_all	*all;

	all = (t_all *)all_info;
	while (1)
		if (all->stop_all == 1 || monitoring_count(all) == 1)
		{
			all->stop_all = 1;
			return (NULL);
		}
}
