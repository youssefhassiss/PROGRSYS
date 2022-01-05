/*ecrire un programme c equivalant a la commande shell:
#cat/etc/passwd | grep 500 | cut -c 1-255
on commence par le pere p3 puis le fils p2 puis le fils p1
p1-->p2-->p3-->*/
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
int pfd1[2], pfd2[2];
int pere(){
close(pfd1[1]);
dup2(pfd1[0],0);
close(pfd1[0]);
execlp("cut", "cut","-d",":","-f1,3,4,7", (char *)0);
printf("cut failed!");
wait(NULL);
return 0;
}

int pfils(){
close(pfd1[0]);
dup2(pfd2[1],1);
close(pfd2[1]);
execlp("cut", "cut","/etc/passwd",(char *)0);
printf("cut failed!");
wait(NULL);
return 2;
}

int fils(){
close(pfd1[0]);
dup2(pfd1[1],1);
close(pfd1[1]);
pipe(pfd2);
switch(fork())
{
	case -1: perror("fork");exit(1);
	case 0: pfils();
	default: {
	close(pfd2[1]);
	dup2(pfd2[0],0);
	close(pfd2[0]);
	execlp("grep","grep","root",(char*)0);
	printf("grep failed");
	wait(NULL);
	}
}
return 1;
}

int main(int argc, char* argv[], char* envp[])
{
pipe(pfd1);
switch(fork())
{
	case -1: perror("fork");exit(1);
	case 0: fils();
	default: pere();
	}
	return EXIT_SUCCESS;
	
}
