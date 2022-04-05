/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasackers <hack@nasa.usa4all>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:46:40 by nasackers         #+#    #+#             */
/*   Updated: 2022/04/05 00:46:41 by nasackers        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int
	str_int(char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		if (*s < '0' || '9' < *s)
			error_exit("philo: usage: use positive number", 1);
		n = *s - '0' + n * 10;
		s++;
	}
	return (n);
}

void
	parse_args(int argc, char **argv, int times[6])
{
	int	i;

	if (argc < 5 || 6 < argc)
		error_exit("philo: usage: bad number of arguments", 1);
	i = 0;
	while (argv[i + 1])
	{
		times[i] = str_int(argv[i + 1]);
		i++;
	}
}
