/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:46:40 by nasackers         #+#    #+#             */
/*   Updated: 2022/07/26 23:20:24 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

//	Transform number (sting) in number (integer)
static int
	str_int(char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		if (*s < '0' || '9' < *s)
			error_exit("philo: usage: use positive number\n", 1);
		n = *s - '0' + n * 10;
		s++;
	}
	return (n);
}

//	Check the good number of arguments
//	Check if the arguments are only digits
//	Put the number value in array number times
void
	parse_args(int argc, char **argv, int times[5])
{
	int	i;

	if (argc < 5 || 6 < argc)
		error_exit("philo: usage: bad number of arguments\n", 1);
	i = 0;
	while (argv[i + 1])
	{
		times[i] = str_int(argv[i + 1]);
		i++;
	}
}
