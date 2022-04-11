#include "main.h"

/*Excuve */
void _execve(char **argVec)
{
        pid_t child_pid;
        int status;
        extern char **environ;

        printf("Starting the execution Process\n");

        child_pid = fork();

        if (child_pid == -1)
        {
                perror("Error: ");
                exit(0);
        }
        else if (child_pid == 0)
        {
                printf("=========================================\n");
                if (execve(argVec[0], argVec, environ) == -1)
                {
                        perror(argVec[0]);
                        exit(0);
                }
                /*SIGKILl: para terminar el proceso*/
                kill(child_pid, SIGKILL);
        }
        else if (child_pid > 0)
        {
                wait(&status);
        }
        printf("Finish the execution Process\n");
}
