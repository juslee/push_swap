#!/bin/bash

# Function to generate random integers
generate_random_numbers() {
	local count=$1
	awk -v count="$count" 'BEGIN {
		srand();
		for (i = 1; i <= count; i++) {
		print int((rand() * 2 - 1) * 2147483647);
		}
	}' | tr '\n' ' '
}

# Check for arguments
if [ $# -lt 1 ]; then
	echo "Usage: $0 <number_of_integers> [checker|wc|both]"
	exit 1
fi

# Arguments
NUMBER=$1
FLAG=$2

# Generate random numbers
ARG=$(generate_random_numbers "$NUMBER")

# Check for the FLAG and execute accordingly
case $FLAG in
  checker)
	echo "Running push_swap and checker"
	ARG=$(generate_random_numbers "$NUMBER"); ./bin/push_swap "$ARG" | ./bin/checker "$ARG"
	;;
  wc)
	echo "Counting operations with wc -l"
	ARG=$(generate_random_numbers "$NUMBER"); ./bin/push_swap "$ARG" | wc -l
	;;
  both)
	echo "Running push_swap, checker, and counting operations"
	ARG=$(generate_random_numbers "$NUMBER"); ./bin/push_swap "$ARG" | ./bin/checker "$ARG"; ./bin/push_swap "$ARG" | wc -l
	;;
  *)
	echo "Running push_swap only"
	ARG=$(generate_random_numbers "$NUMBER"); ./bin/push_swap "$ARG"
	;;
esac
