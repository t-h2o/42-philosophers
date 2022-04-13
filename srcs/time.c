/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:08:22 by nasackers         #+#    #+#             */
/*   Updated: 2022/04/08 13:42:12 by theo             ###   ########.fr       */
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
	struct timeval	time;

	gettimeofday(&time, 0);
	now = (unsigned int)(((time.tv_sec - start->tv_sec) * 1000) \
		+ ((time.tv_usec - start->tv_usec) / 1000));
	return (now);
}
