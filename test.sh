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

# 1. message
msg_green () {
	printf '\e[0;32m%s\n\e[0m' "$1"
}

# 1. message
msg_red () {

	printf '\e[0;31m%s\n\e[0m' "$1"
}

# 1. Comment
# 2. Argument
test_philo () {

	printf "# %s\n" "$1"
	printf "./philo %s\n" "$2"

	if ./philo $2;
	then
		msg_green "Test philo: OK!"

	else
		msg_red "Test philo: KO :/"
		exit 1

	fi; echo

}

# 1. Comment
# 2. Argument
test_error () {

	printf "# %s\n" "$1"
	printf "./philo %s\n" "$2"

	if ! ./philo $2;
	then
		msg_green "Test error: OK!"

	else
		msg_red "Test error: KO :/"
		exit 1

	fi; echo

}

# Test bad usage
test_usage () {

	printf "### Test bad usage\n"

	test_error "not enought arguments" "500 400 200"
	test_error "too much arguments" "12 500 400 200 42 50"
	test_error "not number" "abc 500 400 200 42"
	test_error "negative number" "12 500 -400 200 42"

}

# Test normal usage
test_normal () {

	printf "### Test normal usage\n"

	test_philo "number of times each philosopher must eat" "5 500 400 200 4"

}

file_norm () {

	printf "### Norminette\n"

	if norminette headers srcs > /dev/null;
	then
		msg_green "Norminette: OK!"

	else
		msg_red "Norminette: KO :/"
		exit 1
	fi

}

makere () {

	if make re;
	then
		msg_green "Compilation OK!"
	else
		exit 1
		msg_red "Error of compilation"
	fi

}

# fsanitize Thread
test_thread () {

	printf "### FSANITIZE=thread\n"

	export FSANITIZE=thread
	makere
	test_normal

}

# fsanitize Address
test_address () {

	printf "### FSANITIZE=address\n"

	export FSANITIZE=address
	makere
	test_normal

}

# NO fsanitize
void () {

	printf "### NO FSANITIZE\n"

	export FSANITIZE=void
	makere
	test_usage
	test_normal

}

# Main
main () {

	void
	test_thread
	test_address
	file_norm
	msg_green

}

main 
msg_green "TEST SUCCESS"
