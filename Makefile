CC = gcc
CFLAGS = -std=c99 -O2 -Wall

all: 202 10283 10321 10284-wrong

clean:
	rm *~ 10283 202 10321 10284-wrong
