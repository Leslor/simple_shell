#include "main.h"

/**
 * _free - frees double pointer
 * @av: input double pointer
 *
 * Return: void
 */

void _free(char **av)
{
	int i = 0;

	if (*(av + i))
	{
		free(*(av + i));
	}
	free(av);
}

/**
 * free_env - Frees the the environment copy.
 *
 * Return: void
 */

void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}
