CC = gcc
CFLAGS = -std=c99 -O2 -Wall

executables = 202 10283 10321 10284-wrong

all: $(executables)

clean:
	rm *~ $(executables)
