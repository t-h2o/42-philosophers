
#include		<stdio.h>
#include		<sys/time.h>
#include		<unistd.h>
#include		<pthread.h>

void			time_start(struct timeval *start);
unsigned int	time_now(struct timeval *start);
void			thread(void);
