#
#
# makefile
#
# created by John Van Note
# Updated on 2016-09-20
#
# makefile for the prime_checker.cpp program
#

objects = ./prime_checker.cpp
CC = g++

compile : $(objects)
	$(CC) -c $(objects)

run : compile
	$(CC) -o ./pcoutput.out $(objects)
	pcoutput.out

clean :
	rm *.o *.out
