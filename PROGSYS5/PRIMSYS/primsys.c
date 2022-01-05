
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main ()
{
int return_value ;
return_value = system ("ls -l /");
return return_value ;
}
