/*gcc file.c -o file*/
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <stdlib.h>
int df[2]; /* descripteur de pipe */
char buf [15];
int pere(){close(df[0]);write (df[1],"HelloWorld\n",12); return 0;} /* écriture pipe
*/
int fils() {close(df[1]);read (df[0],buf,12); printf("%s",buf); return 1;}
int main()
{pipe(df); /* creation pipe
*/
switch (fork())
{case -1: perror("fork"); exit(1);
case 0: fils();
default: pere();}

/* lecture pipe */
}
