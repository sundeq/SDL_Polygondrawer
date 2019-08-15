CC=gcc
CFLAGS=-I

polymake: polydrawer.c
	$(CC) -o polydrawer.o polydrawer.c -lSDL2 -lm
