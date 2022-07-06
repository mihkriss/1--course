CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -g
SRC = list.c kp8.c
PROG = kp8

build:
	$(CC) $(CFLAGS) $(SRC) -o $(PROG)

clean:
	rm $(PROG)

