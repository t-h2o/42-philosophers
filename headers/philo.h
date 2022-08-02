/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:31:05 by nasackers         #+#    #+#             */
/*   Updated: 2022/08/02 11:18:02 by melogr@phy       ###   ########.fr       */
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

// args:
//  [0] : number of philosophers
//  [1] : time to die
//  [2] : time to eat
//  [3] : time to sleep
// ?[4] : number of times each philosopher must eat
// start:
typedef struct s_info {
	int	args[5];
	int	start;
}	t_info;

// left fork
// mine fork
// number of philosopher
typedef struct s_philo {
	pthread_t		philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*mine;
	int				*start;
	int				number;
	t_info			*info;
}	t_philo;

// PHILOS

int		init_philo(t_info info, t_philo **philos);
int		start_philo(int nphilo, t_philo *philos);

// PARSING

int		parsing(int argc, char **argv, int infos[5]);

// UTILS STRINGS

void	putnbr_fd(int number, int fd);
void	putstr_fd(char *str, int fd);
void	print_error(char *msg);

#endif	/*	PHILO_H	*/
