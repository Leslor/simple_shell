#include "main.h"

/**
 * prompt - reads the command line
 *
 * Return: the command line as a string
 */

char *prompt(void)
{
	char *input = NULL;
	size_t buf_size = 0;
	ssize_t bytes_read = 0;

	printf("Empezamos el bucle con Prompt\n");
	printf("$ ");
	bytes_read = getline(&input, &buf_size, stdin);
	printf("%ld\n", bytes_read);
	if (bytes_read == -1)
	{
		if (input)
			free(input);
		return(NULL);
	}
	return (input);
}
