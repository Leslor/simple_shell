#include "main.h"

/*Excuve */
int excuve(char **argVec)
{
		printf("Starting the execution Process");
		pid_t child_pid = 0;
		int status;

		child_pid = fork();
//		printf("child_pid = %u\n", child_pid);
//		printf("process :%u\n", getpid());
//		printf("process :%u\n", getppid());

		if (child_pid == -1)
		{
			perror("Error: ");
			exit(0);
		}
		else if (child_pid == 0)
		{
				//char *argVec[] = {"/bin/tail","-n" ,"3", "nasa_19950801.tsv", NULL};
//				//char *envVec[] = {NULL};
//				printf("Start execve: %s\n", argVec[0]);
				printf("=========================================\n");
				if (execve(argVec[0], argVec, NULL) == -1)
						perror("Could not execute execve");
				kill(child_pid,0);
			//	printf("Oops, something went wrong\n");
		}
		else
		{
//			printf("Parent Of parent process, pid = %u\n",getppid());
			wait(&status);
//			printf("parent process, pid = %u\n",getpid()); 
		}
		printf("Finish the execution Process\n");
	return (0);
}
/*Main test*/

int main(void)
{
//	char *av[] = {"/bin/ls", NULL};
	int access_value;
	//evaluation = malloc(sizeof(char)* size(*argv[]))
	char *argv[] = {"/bin/ls","-l", NULL};
	access_value = _access(argv);
	printf("access_value = %d\n",access_value);

	if (access_value == 0)
	{
//		printf("Ingresando an excuve\n");
		excuve(argv);		
	}
	else
	{
		printf("El archivo no es encuentra o no hay permisos, se finaliza el main\n");
	}
	return(0);
}
