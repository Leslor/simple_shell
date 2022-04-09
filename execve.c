#include "main.h"

/*Excuve */
void _execve(char **argVec)
{
		pid_t child_pid;
		int status;

		printf("Starting the execution Process");

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error: ");
			exit(0);
		}
		else if (child_pid == 0)
		{
				printf("=========================================\n");
				if (execve(argVec[0], argVec, NULL) == -1)
						perror("Could not execute execve\n");
				/*SIGKILl: para terminar el proceso*/
				kill(child_pid, SIGKILL);
		}
		else
		{
			wait(&status);
		}
		printf("Finish the execution Process\n");
}

/*Main test
int main(void)
{
	int access_value;
	char *argv[] = {"ls","pwd", NULL};
	access_value = _access(argv);
	printf("access_value = %d\n",access_value);

	if (access_value != 0)
	{
		_execve(argv);		

	}
	else
	{
		perror(argv[0]);
	}
	return(0);
}*/
