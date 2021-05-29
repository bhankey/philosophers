/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:20:05 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/19 14:20:44 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	clear_mem(t_all *all)
{
	int		i;
	char	sem_philo[300];

	sem_unlink("/philo_writing");
	sem_unlink("/philo_forks");
	sem_unlink("/feed_up_philo");
	sem_unlink("/die");
	i = 0;
	while (i < all->num_of_philo)
	{
		str_philo_join(sem_philo, "/philo", i++);
		sem_unlink(sem_philo);
	}
	free(all->philos);
	free(all->pids);
}

void	exit_and_free(t_all *all)
{
	int i;

	i = 0;
	while (i < all->num_of_philo)
		kill(all->pids[i++], SIGKILL);
	clear_mem(all);
	exit(0);
}
