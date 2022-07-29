/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:31:05 by nasackers         #+#    #+#             */
/*   Updated: 2022/07/29 19:12:28 by tgrivel          ###   ########.fr       */
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
	pthread_t		philo;
	pthread_mutex_t	*locker;
	int				number;
	int				*infos;
}	t_philo;

// PHILOS

int		init_philo(int infos[5], t_philo **philos);
int		start_philo(int nphilo, t_philo *philos);

// PARSING

int		parsing(int argc, char **argv, int infos[5]);

// UTILS STRINGS

void	putnbr_fd(int number, int fd);
void	putstr_fd(char *str, int fd);
void	print_error(char *msg);

// BREXIT

void	free_destroy(t_philo *philos, pthread_mutex_t *locker);

#endif	/*	PHILO_H	*/
