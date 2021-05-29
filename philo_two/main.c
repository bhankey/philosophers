/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:20:12 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/19 14:20:41 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	philosophers(t_all *all)
{
	int			i;
	pthread_t	thread;

	i = -1;
	all->start_time = get_time_ms();
	while (++i < all->num_of_philo)
	{
		all->philos[i].die_time = all->start_time + all->time_to_die;
		pthread_create(&thread, NULL, &philo_thread, &(all->philos[i]));
		pthread_detach(thread);
		usleep(50);
	}
}

int		main(int argc, char **argv)
{
	t_all		all;
	pthread_t	mon_d;
	pthread_t	mon_c;

	if (check_args_fill(argc, argv, &all))
		return (print_error("Arguments is incorrect"));
	init_table_philos(&all);
	philosophers(&all);
	pthread_create(&mon_d, NULL, &monitor_d, &all);
	if (all.number_times_to_eat != -1)
	{
		pthread_create(&mon_c, NULL, &monitor_c, &all);
		pthread_join(mon_c, NULL);
	}
	pthread_join(mon_d, NULL);
	all.stop_all = 1;
	clear_mem(&all);
	return (0);
}
