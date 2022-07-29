/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:31:05 by nasackers         #+#    #+#             */
/*   Updated: 2022/07/29 13:59:29 by melogr@phy       ###   ########.fr       */
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

// STRUCTURE

typedef struct s_philo {
	pthread_t	philo;
	int			number;
}	t_philo;

// PHILOS

int		init_philo(int nphilo);

// PARSING

int		parsing(int argc, char **argv, int infos[5]);

// UTILS STRINGS

void	putnbr_fd(int number, int fd);
void	putstr_fd(char *str, int fd);
void	print_error(char *msg);

#endif	/*	PHILO_H	*/
