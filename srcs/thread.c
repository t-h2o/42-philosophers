/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:08:31 by nasackers         #+#    #+#             */
/*   Updated: 2022/07/26 23:04:19 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void
	*display_number(void *arg)
{
	msg_philo("block", 42);
	pthread_mutex_lock((pthread_mutex_t *)arg);
	usleep(1000);
	msg_philo("unblock", 250);
	pthread_mutex_unlock((pthread_mutex_t *)arg);
	usleep(1000);
	return (0);
}

static void
	thread_create(void)
{
	pthread_t		philosopher;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, 0);
	pthread_create(&philosopher, 0, display_number, &mutex);
	printf("parent block\n");
	pthread_mutex_lock(&mutex);
	usleep(1000);
	printf("parent unblock\n");
	pthread_mutex_unlock(&mutex);
	usleep(1000);
}

//static void
//	mutex_init(void)
//{
//
////       int pthread_mutex_init(pthread_mutex_t *restrict mutex,
////           const pthread_mutexattr_t *restrict attr);
//}

void
	thread(void)
{
	thread_create();
}
