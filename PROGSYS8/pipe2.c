/*gcc file.c -o file*/
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <stdlib.h>
int pip[2]; /* descripteur de pipe */
char buf [6];
int pere(){write (pip[1],"hello\n",5); return 0;} /* écriture pipe
*/
int fils() {read (pip[0],buf,5); printf("%s",buf); return 1;}
int main()
{pipe(pip); /* creation pipe
*/
switch (fork())
{case -1: perror("fork"); exit(1);
case 0: fils();
default: pere();}

/* lecture pipe */
}
