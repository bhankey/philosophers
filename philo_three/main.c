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

#include "philo_three.h"

void	philosophers(t_all *all)
{
	int			i;

	i = -1;
	all->start_time = get_time_ms();
	while (++i < all->num_of_philo)
	{
		all->philos[i].die_time = all->start_time + all->time_to_die;
		all->pids[i] = fork();
		if (all->pids[i] < 0)
			exit(1);
		else if (all->pids[i] == 0)
		{
			philo_process(&(all->philos[i]));
			exit(0);
		}
	}
}

int		main(int argc, char **argv)
{
	t_all		all;
	pthread_t	pthread;
	pthread_t	pthread1;

	if (check_args_fill(argc, argv, &all))
		return (print_error("Arguments is incorrect"));
	init_table_philos(&all);
	philosophers(&all);
	pthread_create(&pthread, NULL, &monitor_d, &all);
	if (all.number_times_to_eat != -1)
	{
		pthread_create(&pthread1, NULL, &monitor_c, &all);
		pthread_join(pthread1, NULL);
	}
	pthread_join(pthread, NULL);
	exit_and_free(&all);
	return (0);
}
