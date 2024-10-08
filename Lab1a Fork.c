#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    int pid = getpid();
    int child_id;

    if ((child_id = fork()) > 0)
    {
        printf("I am in the parent process %d\n", pid);
        printf("I am in the parent process %d\n", getpid());
        printf("I am in the parent process %d\n\n", getppid());
    }
    else {
        printf("I am in the child process %d\n", pid);
        printf("I am in the child process %d\n", getpid());
        printf("I am in the child process %d\n", getppid());
    }
}