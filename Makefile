CC = gcc
CFLAGS = -Wall -Werror


daycount: daycount.c
	$(CC) $(CFLAGS) -o daycount daycount.c

clean:
	rm -f daycount

.PHONY: all clean
