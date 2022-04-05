#!/usr/bin/bash

### ARGUMENTS LIST
# number_of_philosophers
# time_to_die
# time_to_eat
# time_to_sleep
# [number_of_times_each_philosopher_must_eat]

message ()	{
	echo -e	"\n------\n$1\n-----\n"
}

message "not enought arguments"
./philo 500 400 200	

message	"too much arguments"
./philo 12 500 400 200 42 50

message "number of times each philosopher must eat"
./philo 12 500 400 200 42

message "infinity"
./philo 12 500 400 200
