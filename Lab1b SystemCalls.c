#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
    int pid = fork();

    if (pid < 0)
    {
        printf("ERROR: Cannot fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("It is the child process and pid is %d\n", getpid());
        for (int i = 0; i < 8; i++)
        {
            printf("%d\n", i);
        }
        exit(0);
    }
    else if (pid > 0)
    {
        printf("It is the process and pid is %d\n", getpid());
        int status;
        wait(&status);
        printf("Child is reaped\n");
    }
}