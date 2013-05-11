CC=gcc
CFLAGS=-c -fPIC
LFLAGS=-shared
FFLAGS=-lhelloworld -L.

DEPS=helloworld.h
OBJECTS=main.c libhelloworld.so

test : $(OBJECTS)
	$(CC) -o test main.c $(FFLAGS)

libhelloworld.so : helloworld.o
	$(CC) $(LFLAGS) -o libhelloworld.so helloworld.o

helloworld.o : helloworld.c
	$(CC) $(CFLAGS) helloworld.c
