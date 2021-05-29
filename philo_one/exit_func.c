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

#include "philo_one.h"

void	clear_mem(t_all *all)
{
	int i;

	pthread_mutex_destroy(&(all->writing));
	i = 0;
	while (i < all->num_of_philo)
	{
		pthread_mutex_destroy(&(all->philos[i].eating));
		pthread_mutex_destroy(&(all->forks[i++]));
	}
	free(all->forks);
	free(all->philos);
}
