/*gcc file.c -o file*/
/*cat tutu*/
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
int fd = open("tutu",O_WRONLY|O_CREAT);
close(STDOUT_FILENO);
dup(fd);
close(fd);
printf("tutu");
return 0;
}
