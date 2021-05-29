/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:20:32 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/19 14:20:34 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		is_num(char *str)
{
	int i;

	i = 0;
	if (*str == '+' || *str == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int		check_value(t_all *all)
{
	if (all->num_of_philo < 2 || all->num_of_philo > 200 ||
	all->time_to_sleep < 60 || all->time_to_eat < 60 || all->time_to_die < 60)
		return (1);
	return (0);
}

int		check_args_fill(int argc, char **argv, t_all *all)
{
	int		i;
	int64_t	num;

	i = 1;
	all->stop_all = 0;
	all->number_times_to_eat = -1;
	if (!(argc == 5 || argc == 6))
		return (1);
	while (i < argc)
	{
		if (is_num(argv[i]) == 0 || ((num = ft_atoi(argv[i])) <= 0))
			return (1);
		if (i == 1)
			all->num_of_philo = num;
		else if (i == 2)
			all->time_to_die = num;
		else if (i == 3)
			all->time_to_eat = num;
		else if (i == 4)
			all->time_to_sleep = num;
		else
			all->number_times_to_eat = num;
		i++;
	}
	return (check_value(all));
}

int		init_one_philo(t_all *all, int i)
{
	char sem_philo[300];

	all->philos[i].i = i;
	all->philos[i].all = all;
	all->philos[i].is_dead = 0;
	all->philos[i].eat_count = 0;
	all->philos[i].last_eating = 0;
	str_philo_join(sem_philo, "/philo", i);
	sem_unlink(sem_philo);
	if ((all->philos[i].eating =
		sem_open(sem_philo, O_CREAT, 0644, 1)) == SEM_FAILED)
	{
		return (1);
	}
	return (0);
}

int		init_table_philos(t_all *all)
{
	int i;

	i = 0;
	all->philos = malloc(sizeof(t_philo) * all->num_of_philo);
	all->pids = malloc(sizeof(pid_t) * all->num_of_philo);
	sem_unlink("/philo_writing");
	if ((all->writing = sem_open("/philo_writing",
						O_CREAT, 0644, 1)) == SEM_FAILED)
		return (semaphore_failed());
	sem_unlink("/philo_forks");
	if ((all->forks = sem_open("/philo_forks",
						O_CREAT, 0644, all->num_of_philo)) == SEM_FAILED)
		return (semaphore_failed());
	sem_unlink("/feed_up_philo");
	if ((all->how_much_feed_up = sem_open("/feed_up_philo",
						O_CREAT, 0644, 0)) == SEM_FAILED)
		return (semaphore_failed());
	sem_unlink("/die");
	if ((all->die = sem_open("/die",
						O_CREAT, 0644, 0)) == SEM_FAILED)
		return (semaphore_failed());
	while (i < all->num_of_philo)
		if (init_one_philo(all, i++))
			return (semaphore_failed());
	return (0);
}
