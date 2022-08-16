#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>

void	header(int nphilo)
{
	int	i;

	i = 0;
	printf("TIME\t\t");
	while (i++ < nphilo)
		printf("%d\t\t", i);
	printf("\n");
}

void	print_line(char line[64][64], int nphilo)
{
	int	i = 0;

	while (nphilo--)
		printf("%s\t\t", line[++i]);
}

void	print_animation(FILE *log, int nphilo)
{
	int		time, philo, start;
	char	msg[64];
	char	line[64][64];
	int		i[64];

	start = 0;

	printf("0\t\t");
	memset(line[0], 0, 64 * 64);
	memset(i, 0, 64 * 4);
	while (fscanf(log, "%d %d %99[^\n]", &time, &philo, msg) == 3)
	{
		if ((time / 10 != start / 10))
		{
			print_line(line, nphilo);
			memset(line[0], 0, 64 * 64);
			memset(i, 0, 64 * 4);
			start = time;
			printf("\n");
			printf("%d\t\t", time);
		}
		if (strcmp(msg, "has taken a fork") == 0)
			line[philo][i[philo]++] = 'F';
		if (strcmp(msg, "is sleeping") == 0)
			line[philo][i[philo]++] = 'S';
		if (strcmp(msg, "is thinking") == 0)
			line[philo][i[philo]++] = 'T';
		if (strcmp(msg, "is eating") == 0)
			line[philo][i[philo]++] = 'E';
		if (strcmp(msg, "has died") == 0)
			line[philo][i[philo]++] = 'D';
	}
	print_line(line, nphilo);
	printf("\n");
}

int	main(int argc, char **argv)
{
	FILE *log;

	if (argc != 3)
		printf("1. argument: Path on the log file\n2. argument: Number of philo\n");
	if (argc != 3)
		return (1);
	log = fopen(argv[1], "r");
	if (log == 0)
		printf("Error: open file\n");
	if (log == 0)
		return (1);

	header(atoi(argv[2]));
	print_animation(log, atoi(argv[2]));

	fclose(log);
	return (0);
}
