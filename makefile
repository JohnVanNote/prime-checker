# makefile
#
# makes the shit in this directory
#
# created by john van note

objects = ./prime_checker.cpp
CC = g++

compile : $(objects)
	$(CC) -c $(objects)
run : compile
	$(CC) -o ./pcoutput.out $(objects)
	pcoutput.out
clean :
	rm *.o *.out
