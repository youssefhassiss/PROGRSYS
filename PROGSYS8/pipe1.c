/*gcc file.c -o file*/
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
int main( int argc, char ** argv )
{
char buffer[BUFSIZ+1];
int fd[2],w,r;
pipe(fd); /* create the cd prog pipe */
/* write into the pipe */
w =write(fd[1], "Hello World\n", strlen("Hello World\n"));
/* read the pipe and print the read value */
r= read(fd[0], buffer, BUFSIZ);
printf("%s", buffer);
}
