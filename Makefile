CFLAGS=-Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11 -O3

main: main.c myfuncs.o
	gcc $(CFLAGS) main.c -o main myfuncs.o

myfuncs.o: myfuncs.c myfuncs.h
	gcc $(CFLAGS) -c myfuncs.c

clean:
	rm *.txt *.o main
