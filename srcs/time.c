/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:27:57 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/02 16:20:08 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

//	set start time
void
	time_start(struct timeval *start)
{
	gettimeofday(start, 0);
}

//	return current time [ms]
unsigned int
	time_now(struct timeval *start)
{
	unsigned int	now;
	struct			timeval time;

	gettimeofday(&time, 0);
	now = (unsigned int)(((time.tv_sec - start->tv_sec) * 1000) \
		+ ((time.tv_usec - start->tv_usec) / 1000));
	return (now);
}

uint64_t
	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}
