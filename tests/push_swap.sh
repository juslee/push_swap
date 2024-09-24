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

# Detect OS and set VALGRIND variable
UNAME_S=$(uname -s)
if [ "$UNAME_S" = "Darwin" ]; then
	# VALGRIND="leaks --atExit --list --"
	VALGRIND="leaks --atExit --"
	# VAL_CHECK="leaks_check"
else
	VALGRIND="valgrind --leak-check=full --show-leak-kinds=all -s"
	# VAL_CHECK="val_check"
fi

# Check for arguments
if [ $# -lt 1 ]; then
	echo "Usage: $0 <number_of_integers> [checker|wc|both]"
	exit 1
fi

# Arguments
PUSH_SWAP="./bin/push_swap"
CHECKER="./tests/checker_Mac"
NUMBER=$1
FLAG=$2

# Generate random numbers
ARG=$(generate_random_numbers "$NUMBER")

# Check for the FLAG and execute accordingly
case $FLAG in
  checker)
	echo "Running push_swap and checker"
	ARG=$(generate_random_numbers "$NUMBER")
	$VALGRIND $PUSH_SWAP "$ARG"
	$PUSH_SWAP "$ARG" > results.txt
	$VALGRIND $CHECKER "$ARG" < results.txt
	;;
  wc)
	echo "Counting operations with wc -l"
	ARG=$(generate_random_numbers "$NUMBER")
	$VALGRIND $PUSH_SWAP "$ARG"
	$PUSH_SWAP "$ARG" > results.txt
	$VALGRIND wc -l < results.txt
	;;
  both)
	echo "Running push_swap, checker, and counting operations"
	ARG=$(generate_random_numbers "$NUMBER")
	$VALGRIND $PUSH_SWAP "$ARG"
	$PUSH_SWAP "$ARG"  > results.txt
	$VALGRIND $CHECKER "$ARG" < results.txt
	$VALGRIND wc -l < results.txt
	;;
  *)
	echo "Running push_swap only"
	ARG=$(generate_random_numbers "$NUMBER");
	$VALGRIND $PUSH_SWAP "$ARG"
	;;
esac
