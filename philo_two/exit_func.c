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

#include "philo_two.h"

void	clear_mem(t_all *all)
{
	int		i;
	char	sem_philo[300];

	sem_unlink("/philo_writing");
	sem_unlink("/philo_forks");
	i = 0;
	while (i < all->num_of_philo)
	{
		str_philo_join(sem_philo, "/philo", i++);
		sem_unlink(sem_philo);
	}
	free(all->philos);
}
