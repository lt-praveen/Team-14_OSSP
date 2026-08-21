#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    char cmd[20];
    pid_t pid;

    printf("Enter Linux command: ");
    scanf("%s", cmd);

    pid = fork();

    if (pid == 0)
    {
        printf("Child PID : %d\n", getpid());

        execlp(cmd, cmd, NULL);

        printf("Invalid Command!\n");
        exit(1);
    }
    else if (pid > 0)
    {
        printf("Parent PID : %d\n", getpid());

        wait(NULL);

        printf("Child process completed.\n");
    }
    else
    {
        printf("Fork failed!\n");
    }

    return 0;
}
