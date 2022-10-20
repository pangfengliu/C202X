CC = gcc
CFLAGS = -std=c99 -O2 -Wall

executables = 202 50005 50084 50196 50197 50199 50200 50203 50204 50225 50226 50228 50053 50126 50206 50209

50126: 50126.c 50126-main.c
	$(CC) $(CFLAGS) 50126.c 50126-main.c -o $@

50207: 50207.c 50207-main.c
	$(CC) $(CFLAGS) 50207.c 50207-main.c -o $@

all: $(executables)

clean:
	rm *~ *.o $(executables)
