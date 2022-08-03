/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:31:05 by nasackers         #+#    #+#             */
/*   Updated: 2022/08/04 00:08:04 by melogr@phy       ###   ########.fr       */
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
	int				args[5];
	struct timeval	start;
	pthread_mutex_t	*print_msg;
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

// BREXIT

void	free_destroy(t_info *info, t_philo *philo);

// MESSAGE

void	p_eat(t_philo *philo);
void	p_sleep(t_philo *philo);
void	p_think(t_philo *philo);

// PHILOS

int		start_philo(t_info *info, t_philo **philos);
int		end_philo(int nphilo, t_philo *philos);

// PARSING

int		parsing(int argc, char **argv, int infos[5]);

// TIME

void	time_start(struct timeval *start);
int		time_now(struct timeval *start);

// UTILS STRINGS

void	putnbr_fd(int number, int fd);
void	putstr_fd(char *str, int fd);
void	print_error(char *msg);

#endif	/*	PHILO_H	*/
