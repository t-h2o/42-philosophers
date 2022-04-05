/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:08:06 by nasackers         #+#    #+#             */
/*   Updated: 2022/04/04 23:08:11 by nasackers        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int argc, char **argv)
{
	struct timeval  start;
	int				times[6];

	parse_args(argc, argv, times);
	thread();
	time_start(&start);
	time_now(&start);
	return (0);
}
//	init philo
//	init supervasor
//	start time
//	start simulation

