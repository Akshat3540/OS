#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
    printf("Before execv()\n");
    execv("/bin/ls", argv);
    printf("ERROR: execv() failed\n");
}