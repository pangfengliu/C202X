CC = gcc
CFLAGS = -std=c99 -O2 -Wall

executables = 202 50084 50196 50197 50199 50200 50203 50204 50225 50226 50228 

all: $(executables)

clean:
	rm *~ $(executables)
