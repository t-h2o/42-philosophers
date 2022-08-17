/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:54:48 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/17 17:22:01 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// Create a mutex
static pthread_mutex_t	*crt_mutex(void)
{
	pthread_mutex_t	*locker;

	locker = malloc(sizeof(pthread_mutex_t) * 1);
	if (locker == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (0);
	}
	pthread_mutex_init(locker, 0);
	return (locker);
}

static inline int	fill_philo(t_philo *philo, t_info *info, int i)
{
	philo->last_eat = 0;
	philo->number = i + 1;
	philo->info = info;
	philo->count = info->args[4];
	philo->mine = crt_mutex();
	if (philo->mine == 0)
		return (2);
	philo->data_philo = crt_mutex();
	if (philo->data_philo == 0)
		return (2);
	return (0);
}

static int	init_philo(t_info *info, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * info->args[0]);
	if (*philos == 0)
	{
		print_error("Error: Philo: System: Malloc return 0\n");
		return (2);
	}
	i = -1;
	while (++i < info->args[0])
	{
		if (fill_philo(&((*philos)[i]), info, i))
			return (2);
		if (i != 0)
			((*philos)[i]).left = ((*philos)[i - 1]).mine;
	}
	if (i == 1)
		((*philos)[0]).left = 0;
	else
		((*philos)[0]).left = ((*philos)[i - 1]).mine;
	return (0);
}

int	start_philo(t_info *info, t_philo **philos)
{
	int	i;

	if (init_philo(info, philos))
		return (2);
	info->data_died = crt_mutex();
	if (info->data_died == 0)
		return (2);
	info->print_msg = crt_mutex();
	if (info->print_msg == 0)
		return (2);
	info->died = 0;
	time_start(&(info->start));
	i = 1;
	while (i < info->args[0])
	{
		if (pthread_create(&(((*philos)[i]).philo), 0, &life, &((*philos)[i])))
		{
			print_error("Error: Philo: System: pthread_join\n");
			return (1);
		}
		i += 2;
	}
	i = 0;
	while (i < info->args[0])
	{
		if (pthread_create(&(((*philos)[i]).philo), 0, &life, &((*philos)[i])))
		{
			print_error("Error: Philo: System: pthread_join\n");
			return (1);
		}
		i += 2;
	}
	monitor(*philos, info);
	return (0);
}
