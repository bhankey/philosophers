/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:54:37 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/24 22:54:38 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	monitoring_count(t_all *all)
{
	int i;

	i = 0;
	while (i < all->num_of_philo)
	{
		if (all->stop_all == 1)
			return ;
		sem_wait(all->how_much_feed_up);
		i++;
	}
	sem_wait(all->writing);
	printf("all was feed up\n");
	all->stop_all = 1;
	sem_post(all->die);
}

void	*monitor_d(void *all_info)
{
	t_all	*all;

	all = all_info;
	sem_wait(all->die);
	all->stop_all = 1;
	return (NULL);
}

void	*monitor_c(void *all_info)
{
	t_all	*all;

	all = (t_all *)all_info;
	monitoring_count(all);
	return (NULL);
}
