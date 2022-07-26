/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:08:06 by nasackers         #+#    #+#             */
/*   Updated: 2022/07/26 23:02:35 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"
#include	"libft.h"

//		MAIN
//	1. parse arguments
//	2. init philo
//	3. init supervisor
//	4. start time
//	5. start simulation
//
//		TIMES
//	times[0]	: number of philosophers
//	times[1]	: time to die
//	times[2]	: time to eat
//	times[3]	: time to sleep
//	(times[4])	: number of times each philosopher must eat
int	main(int argc, char **argv)
{
	struct timeval	start;
	int				times[5];

	parse_args(argc, argv, times);

	for (int i = 0; i < 6; i++)
		printf("times %d\n", times[i]);

	thread();
	time_start(&start);
	time_now(&start);
	return (0);
}
