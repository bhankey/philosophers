/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhankey <bhankey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 02:55:54 by bhankey           #+#    #+#             */
/*   Updated: 2021/02/22 02:55:56 by bhankey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_itoa_to_print(char *str, char **ptr, unsigned int n)
{
	char	tmp[18];
	char	*tp;

	tp = tmp;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = ' ';
		*ptr = &(str[2]);
		return ;
	}
	while (n)
	{
		*tp++ = (n % 10) + '0';
		n /= 10;
	}
	while (tp > tmp)
		*str++ = *--tp;
	*str = ' ';
	*ptr = str + 1;
}

void	ft_itoa_to_init(char *str, unsigned int n)
{
	char	tmp[18];
	char	*tp;

	tp = tmp;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (n)
	{
		*tp++ = (n % 10) + '0';
		n /= 10;
	}
	while (tp > tmp)
		*str++ = *--tp;
	*str = '\0';
}
