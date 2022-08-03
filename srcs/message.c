/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:06:45 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/02 18:06:31 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// timestamp_in_ms X is eating
// lock
// eat
// unlock

static void	msg_philo(int nphilo, char *msg)
{
	putnbr_fd(42, 1);
	putstr_fd(" ", 1);
	putnbr_fd(nphilo, 1);
	putstr_fd(msg, 1);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->mine);
	pthread_mutex_lock(philo->left);
	msg_philo(philo->number, " has taken fork\n");
	msg_philo(philo->number, " is eating\n");
	usleep(philo->info->args[3] * 1000);
	pthread_mutex_unlock(philo->mine);
	pthread_mutex_unlock(philo->left);
}

// timestamp_in_ms X is sleeping
// timestamp_in_ms X has taken a fork
// timestamp_in_ms X is thinking
// timestamp_in_ms X died
