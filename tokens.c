#include "main.h"

/**
 * tokenizer - - function that create tokens
 * @input: is a char pointer of a string
 * @delimt: is a char pointer delimitator
 *
 * Return: double pointer to strings
 */

char **tokenizer(char *input, char *delimt)
{
	int count = 0;
	char **av = NULL;

	av = malloc(sizeof(char *) * 1024);

	if (!av)
	{
		free(input);
		return (NULL);
	}
	while ((av[count] = strtok(input, delimt)) != NULL)
	{
		input = NULL;
		count++;
	}
	return (av);
}
