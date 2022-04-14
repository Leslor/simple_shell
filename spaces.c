#include "main.h"

/**
 * spaces - deletes spaces and tabulations at the begin
 * @input: input
 *
 * Return: New input without spaces and tabs at the begin
 */

char *spaces(char *input)
{
	int i = 0, j = 0;
	char *result = NULL;

	result = malloc(sizeof(char) * strlen(input));
	if (result == NULL)
		return (NULL);

	for (i = 0; (input[i] == 32) || (input[i] == 9); i++)
		;

	for (j = 0; input[i] != '\0'; i++, j++) /* entra algo más al input*/
		result[j] = input[i];
	result[j] = '\0';
	free(input);
	return (result);
}
