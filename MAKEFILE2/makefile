OBJECTS = complexe.o useComplexe.o
CC = gcc
CFLAGS = -Wall 
GFLAGS = -lm
useComplexe : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(GFLAGS) -o useComplexe
useComplexe.o : useComplexe.c complexe.h
	$(CC)  -c useComplexe.c
complexe.o : complexe.c complexe.h
	$(CC)  -c complexe.c
