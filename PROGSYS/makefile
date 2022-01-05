useComplexe : useComplexe.o complexe.o
	gcc -Wall complexe.o useComplexe.o -lm -o useComplexe

useComplexe.o : useComplexe.c complexe.h
	gcc -Wall -c useComplexe.c

complexe.c : complexe.c complexe.h
	gcc -Wall -c complexe.c
clean :
	rm -f useComplexe *.o
