#include <stdlib.h>
#include <stdio.h>
#include "complexe.h"
#include <unistd.h>
#include <errno.h>

int main (void) {
pid_t pid_fils;
do {
pid_fils = fork();
Complexe z1,z2,z3;
z1 = nouveauComplexe ( 1., 0.);
z2 = nouveauComplexe ( 0., 1.);
z3 = plus ( z1, z2);
printf("Module de z3 : %f\n",module( z3 ) );
printf("Argument de z3 : %f\n", argument( z3 ));
} while ((pid_fils == -1) && (errno == EAGAIN));
if (pid_fils == -1){
fprintf(stderr, "fork() impossible, errno=%d\n", errno);
return 1;
}
if (pid_fils == 0) {
/* processus fils */
fprintf(stdout, "Fils : PID=%ld, PPID=%ld\n",
(long)getpid(), (long)getppid());
return 0;
} else {
/* processus père */
fprintf(stdout, "Pere : PID=%ld, PPID=%ld, PID fils=%ld\n",
(long)getpid(), (long)getppid(), (long)pid_fils);
return 0;
}
}
