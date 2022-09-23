CC = gcc
CFLAGS = -std=c99 -O2 -Wall

executables = 202 10283 10321 10284-wrong 10320 50200 50199

all: $(executables)

clean:
	rm *~ $(executables)
