#
#
# makefile
#
# created by John Van Note
# Updated on 2016-09-20
#
# makefile for the prime_checker.cpp program
#

objects=./prime_checker.cpp
out=./pcoutput.out
CC=g++

compile : $(objects)
	$(CC) -c $(objects)

output : compile
	$(CC) -o $(out) $(objects)

run : output
	$(out)

test : output
	$(out) 3
	num=1; \
	while [[ $$num -le 10 ]]; do \
	$(out) $$num; \
	(( num = num + 1 ));\
	done

clean :
	rm *.o *.out
