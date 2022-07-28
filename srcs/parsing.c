/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:13:54 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/07/28 16:59:13 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// Check if all string are digits
static int	check_number(char **args)
{
	int	i;

	while (*args)
	{
		i = 0;
		while ('0' <= (*args)[i] && (*args)[i] <= '9')
			++i;
		if ((*args)[i] != 0)
		{
			print_error("Error: Philo: Usage: Not all argument is digits\n");
			return (1);
		}
		++args;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (argc < 5 || 6 < argc)
	{
		print_error("Error: Philo: Usage: Bad number of arguments\n");
		return (1);
	}
	++argv;
	if (check_number(argv))
		return (1);
	return (0);
}
