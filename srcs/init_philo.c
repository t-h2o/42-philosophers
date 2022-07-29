/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:54:48 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/29 15:49:46 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	*life(void *arg)
{
	t_philo	*me;

	me = arg;
	pthread_mutex_lock(me->locker);
	sleep(1);
	putnbr_fd(me->number, 1);
	putstr_fd(": I'm alive\n", 1);
	pthread_mutex_unlock(me->locker);
	return (0);
}

int	init_philo(int nphilo, t_philo **philos)
{
	int				i;
	pthread_mutex_t	*locker;

	locker = malloc(sizeof(pthread_mutex_t) * 1);
	if (locker == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (2);
	}
	pthread_mutex_init(locker, 0);
	*philos = malloc(sizeof(t_philo) * nphilo);
	if (*philos == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (2);
	}
	i = -1;
	while (++i < nphilo)
	{
		((*philos)[i]).number = i + 1;
		((*philos)[i]).locker = locker;
		if (pthread_create(&(((*philos)[i]).philo), 0, &life, &((*philos)[i])))
		{
			print_error("Error: Philo: System: pthread_join\n");
			return (1);
		}
	}
	return (0);
}
