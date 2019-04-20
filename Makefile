all: daycount

daycount: daycount.c
	gcc -o daycount daycount.c -Wall -Werror -g

clean:
	rm -f daycount

.PHONY: all clean
