/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:31:05 by nasackers         #+#    #+#             */
/*   Updated: 2022/07/29 12:58:44 by melogr@phy       ###   ########.fr       */
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

// PHILOS

int		init_philo(int nphilo);

// PARSING

int		parsing(int argc, char **argv, int infos[5]);

// UTILS STRINGS

void	putstr_fd(char *str, int fd);
void	print_error(char *msg);

#endif	/*	PHILO_H	*/
