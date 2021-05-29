/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:20:26 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/19 14:20:36 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		print_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}

void	print_message(char *message, t_philo *philo)
{
	char str[300];
	char *ptr;
	char *ptr_2;

	if (philo->all->stop_all == 1)
		return ;
	sem_wait(philo->all->writing);
	ft_itoa_to_print(str, &ptr, get_time_ms() - philo->all->start_time);
	ft_itoa_to_print(ptr, &ptr_2, philo->i + 1);
	while (*message != '\0')
		*(ptr_2++) = *(message++);
	*(ptr_2++) = '\n';
	*(ptr_2++) = '\0';
	write(1, str, ft_strlen(str));
	sem_post(philo->all->writing);
}

int		semaphore_failed(void)
{
	write(2, "semaphore failed\n", 17);
	return (1);
}
