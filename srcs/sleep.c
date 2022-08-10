/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:37:36 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/10 18:49:53 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// 1. Sleep
// 2. Wait the time's sleep
int	p_sleep(t_philo *philo)
{
	int	begin;
	int	now;

	begin = time_now(&(philo->info->start));
	now = begin;
	msg_philo(" is sleeping\n", philo, begin);
	while (now - begin < philo->info->args[3])
	{
		usleep(100);
		now = time_now(&(philo->info->start));
		if (ifdead(philo))
			return (0);
	}
	return (0);
}
