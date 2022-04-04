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

int	main(void)
{
	struct timeval  start;
	unsigned int	now;

	time_start(&start);
	now = time_now(&start);
	printf("%d [ms]\n", now);
	return (0);
}

