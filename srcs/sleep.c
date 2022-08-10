/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:37:36 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/09 00:37:57 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// timestamp_in_ms X is sleeping
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