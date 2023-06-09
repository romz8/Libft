#!/bin/bash
FLAGS = -Wall -Wextra -Werror
make bonus
cc ${FLAGS} -c main_test.c -o main_test.o

cc *.o  -o test_program
./test_program
make fclean
rm -f test_program
