#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
char *cmd[] = {"who", "ls", "date" ,"pwd"};
int i;
while( 1 )
{
	printf( "0=who 1=ls 2=date 3=pwd 4=Quitter: " );
	scanf( "%d", &i );
	if(i==4) exit(0);
	if(fork() == 0)
	{ /* child */
		execlp( cmd[i], cmd[i], NULL);
		printf( "execlp failed\n" );
		exit(1);
	}
	else
	{ /* parent */
		wait( (int *)0 );
		printf( "child finished\n" );
        }
} /* while */
} /* main */
