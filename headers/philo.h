/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:31:05 by nasackers         #+#    #+#             */
/*   Updated: 2022/07/25 20:40:55 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//	HEADERS

# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/time.h>
# include	<unistd.h>
# include	<pthread.h>
# include	"libft.h"

//	TIME

void			time_start(struct timeval *start);
unsigned int	time_now(struct timeval *start);

//	THREAD

void			thread(void);

//	PARSE

void			parse_args(int argc, char **argv, int times[5]);

//	MESSAGE

void			msg_philo(char *msg, int id);

//	ERROR

void			error_exit(char *s, int value);

#endif	/*	PHILO_H	*/
