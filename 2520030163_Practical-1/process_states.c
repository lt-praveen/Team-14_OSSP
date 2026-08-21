#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("=== BEFORE FORK ===\n");
    printf("Parent PID  : %d\n", getpid());
    printf("Parent PPID : %d\n", getppid());
    printf("State       : Parent is Running\n\n");

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0)
    {
        printf("=== CHILD PROCESS ===\n");
        printf("Child PID  : %d\n", getpid());
        printf("Child PPID : %d\n", getppid());
        printf("State      : Child is Running\n");

        printf("Child going to sleep...\n");
        sleep(10);

        printf("State      : Child is Running again\n");
        printf("Child terminating...\n");

        exit(0);
    }
    else
    {
        printf("=== PARENT PROCESS ===\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);
        printf("State      : Parent is Waiting\n");

        wait(NULL);

        printf("State      : Child Terminated\n");
        printf("State      : Parent is Running again\n");
    }

    return 0;
}
