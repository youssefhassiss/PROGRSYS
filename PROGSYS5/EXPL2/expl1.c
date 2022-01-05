/*https://kamechnoue.wordpress.com/programmation-systeme/*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(){
	if(fork()){
	fork() && (fork()||(fork()&&fork()));
	printf("hello!\n");
	}
	else{
	fork();
	sleep(2);
	printf("hi!\n");
	}
	return 0;
}
