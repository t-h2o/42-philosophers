/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:55:23 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/28 16:28:54 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

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
	(void)argc;
	(void)argv;
	putstr_fd("philo\n", 1);
	print_error("Error: Philo\n");
}
