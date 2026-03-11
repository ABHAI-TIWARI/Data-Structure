CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: build

build: out

out.o: main.c
	$(CC) $(CFLAGS) -c main.c -o out.o

out: out.o
	$(CC) out.o -o out

output: out
	./out

clean:
	rm -f out.o out

.PHONY: all build output clean