#!/usr/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melogr@phy <tgrivel@student.42lausanne.ch  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 16:51:30 by melogr@phy        #+#    #+#              #
#    Updated: 2022/07/23 16:58:23 by melogr@phy       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


### ARGUMENTS LIST
# number_of_philosophers
# time_to_die
# time_to_eat
# time_to_sleep
# [number_of_times_each_philosopher_must_eat]

# 1. Comment
# 2. Argument
test_philo () {

	printf "# %s\n" "$1"
	printf "./philo %s\n" "$2"
	./philo $2
	echo

}

test_usage () {

	printf "###Test bad usage\n"
	test_philo "not enought arguments" "500 400 200"
	test_philo "too much arguments" "12 500 400 200 42 50"

}

test_normal () {

	printf "###Test normal usage\n"
	test_philo "number of times each philosopher must eat" "12 500 400 200 42"
	test_philo "infinity" "12 500 400 200"

}

main () {

	test_usage
	test_normal

}

main
