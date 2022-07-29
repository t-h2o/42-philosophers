#include	"philo.h"

void	free_destroy(t_philo *philos, pthread_mutex_t *locker)
{
	if (locker)
		pthread_mutex_destroy(locker);
	free(philos->locker);
	free(philos);
}
