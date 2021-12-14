OBJECTS = complexe.o useComplexe.o
CC = gcc
CFLAGS = -Wall -g
useComplexe : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o useComplexe
useComplexe.o : useComplexe.c complexe.h
	$(CC) $(CFLAGS) -c useComplexe.c
complexe.o : complexe.c complexe.h
	$(CC) $(CFLAGS) -c complexe.c
