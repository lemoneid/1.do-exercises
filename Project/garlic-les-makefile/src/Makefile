CC = gcc
CFLAGS = -std=c99 -Wall -Werror

.PHONY: clean
ncat: ncat.o roman.o roman.h 
	$(CC) $(CFLAGS) -o ncat ncat.o roman.o
roman.o: roman.c roman.h
	$(CC) $(CFLAGS) -c -o roman.o roman.c
ncat.o: ncat.c roman.h
	$(CC) $(CFLAGS) -c -o ncat.o ncat.c

clean:
	$(RM) -- *.o ncat
