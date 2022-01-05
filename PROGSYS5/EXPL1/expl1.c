/*https://kamechnoue.wordpress.com/programmation-systeme/*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(){
	fork();
	fork();
	fork();
	printf("hello!\n");
	exit(0);
}
