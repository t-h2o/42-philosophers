/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 16:13:54 by melogr@phy        #+#    #+#             */
/*   Updated: 2022/08/11 15:11:09 by melogr@phy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

// Convert a string into an integer
static int	strint(char *str)
{
	int	n;

	if (str == 0)
		return (-1);
	n = 0;
	while (*str)
	{
		n = (*str - '0') + 10 * n;
		++str;
	}
	return (n);
}

// Fill table of number from the arguments
static void	fill_tab(char **args, int infos[5])
{
	int	i;

	i = 5;
	while (i--)
	{
		infos[i] = strint(args[i]);
	}
}

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

// Parsing
// 1. Check the number of arguments (we need between 5-6 arguments)
// 2. Check if arguments are numbers
// 3. Transform string to integer
int	parsing(int argc, char **argv, int infos[5])
{
	if (argc < 5 || 6 < argc)
	{
		print_error("Error: Philo: Usage: Bad number of arguments\n");
		return (1);
	}
	++argv;
	if (check_number(argv))
		return (1);
	fill_tab(argv, infos);
	return (0);
}
