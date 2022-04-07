#include "main.h"

int main(void)
{
	char *cmd_l = NULL;
	char *string, **av;
	int status, i;
	int execution;
	pid_t child_pid;
	size_t buf_size = 0;
	ssize_t bytes_read = 0;

/*Display promtp " $ " and wait an input */
	while (1)
	{
		printf("$ ");
/*An array of characteres which a copy of the string taken from stdin.*/
		bytes_read = getline(&cmd_l, &buf_size, stdin);
		printf("%ld\n", bytes_read);
		if (bytes_read == -1)
		{
			free(cmd_l);
			return (0);
		}
		string = malloc(strlen(cmd_l));
		if (!string)
		{
			free(string);
			return(0);
		}

		for (i = 0; i < strlen(cmd_l); i++)
		{
			string[i] = cmd_l[i];
		}
		string[i] = '\0';
/* string[] = {"tail -l -n"}*/
		free(cmd_l);
/* Execute tokenizer */
		av = tokenizer(string);
		execution = _execve(av);
/* Executes the program referred to by avg*/
		printf("Este es el av[%d]: %s ", i, *av);
		free(string);
	}
	return (0);
}
