all: 50108-3 50108-5

CC = gcc
CFLAGS = -std=c99 -O2 -Wall

50108-5:
	gcc -std=c99 -O2 -Wall -DMAXLENGTH=5 50108.c main.c -o $@

50108-3: 
	gcc -std=c99 -O2 -Wall -DMAXLENGTH=3 50108.c main.c -o $@

clean:
	rm *~ *.o 50108-3 50108-5
