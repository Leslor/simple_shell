#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h>
#include <errno.h>  
#include <sys/wait.h>
#include <signal.h>

int execve(char **argv)
{
		pid_t child_pid = 0;
		int status;

		child_pid = fork();
		printf("child_pid = %u\n", child_pid);
		printf("process :%u\n", getpid());
		printf("process :%u\n", getppid());
		if (child_pid == -1)
		{
			perror("Error: ");
			exit(0);
		}
		else if (child_pid == 0)
		{
				//char *argVec[] = {"/bin/tail","-n" ,"3", "nasa_19950801.tsv", NULL};
				//char *envVec[] = {NULL};
				printf("Start execve: %s\n", argVec[0]);
				printf("=========================================\n");
				if (execve(*argVec[0], *argVec, envVec) == -1)
						perror("Could not execute execve");
				kill(child_pid,0);
				printf("Oops, something went wrong\n");
		}
		else
		{
			printf("Parent Of parent process, pid = %u\n",getppid());
			wait(&status);
			printf("parent process, pid = %u\n",getpid()); 
		}
	return (0);
}

