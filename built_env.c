#include "main.h"

/**
  * built_or_env - function that validates
  * and built or env
  * @av: array eoth values to evaluate
  * Return: 0 if is a buit or 1 other value
  */

int built_or_env(char **av)
{
		char *exit = "exit";
		char *env = "env";

		if (strcmp(av[0], exit) == 0)
			return (0);
		if ( strcmp(av[0], env) == 0)
			return (1);
		else
			return (2);
}

/**
  * _execute_built - function that validates
  * and built or env
  * @av: array eoth values to evaluate
  * Return: 0 
*/
void _execute_built(int i)
{
		extern char **environ;
		if (i == 0)
		{
		printf("Es Exit\n");
		exit(1);
		}
		if (i == 1)
		{
			printf("Es env");
			while (environ[i])
			{
				write(STDOUT_FILENO, environ[i], strlen(environ[i]));
				write(STDOUT_FILENO, "\n", 1);
				i++;
			}
		}
}