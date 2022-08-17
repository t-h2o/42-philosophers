/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:37:36 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/17 21:48:14 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// 1. Sleep
// 2. Wait the time's sleep
int	p_sleep(t_philo *philo)
{
	msg_philo(" is sleeping\n", philo, time_now(&(philo->info->start)));
	return (my_sleep(philo, philo->info->args[3]));
}
