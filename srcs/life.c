/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:06:45 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/16 16:52:17 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died
void	msg_philo(char *msg, t_philo *philo, int time)
{
	pthread_mutex_lock(philo->info->data_died);
	if (philo->info->died == 0)
	{
		pthread_mutex_unlock(philo->info->data_died);
		pthread_mutex_lock(philo->info->print_msg);
		putnbr_fd(time, 1);
		putstr_fd(" ", 1);
		putnbr_fd(philo->number, 1);
		putstr_fd(msg, 1);
		pthread_mutex_unlock(philo->info->print_msg);
	}
	pthread_mutex_unlock(philo->info->data_died);
}

// Nothing
// while (1)
//   eat
//   sleep
//   think
void	*life(void *arg)
{
	t_philo	*me;
	int		i;

	me = arg;
	i = me->count;
	while (i == -1 || i--)
	{
		if (p_eat(me))
			return (0);
		p_sleep(me);
		p_think(me);
	}
	pthread_mutex_lock(me->data_philo);
	me->count = 0;
	pthread_mutex_unlock(me->data_philo);
	return (0);
}
