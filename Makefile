CFLAGS=-Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11

main: main.c
	gcc $(CFLAGS) main.c -o main