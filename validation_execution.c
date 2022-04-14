#include "main.h"

/**
 * valid_exec - function that validates
 * @av: array eoth values to evaluate
 * @valid_built_env: and int variable
 * Return: nothin
 */

void valid_exec(char **av, int valid_built_env)
{
	char **argv = NULL;

	if (valid_built_env == 0 || valid_built_env == 1)
	{
		_execute_built(valid_built_env);
	}
	if (valid_built_env == 2)
	{
		printf("SScript\n");
		argv = validation(av);
		if (argv == NULL)
		{
			perror(av[0]);
			return;
		}
		else
			_execve(argv);
	}
}
