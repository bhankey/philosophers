/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 02:55:23 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/22 02:55:25 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

u_int64_t	get_time_from_start_ms(t_all *all)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000 + timeval.tv_usec / 1000) - all->start_time);
}

u_int64_t	get_time_ms(void)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}
