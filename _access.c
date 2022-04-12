#include"main.h"

/**
 * _access - evaluates if a *av exist in the env
 * @av: argument vector
 *
 * Return: rt_value 0 if the file exist, or -1 otherwise.
 */

int  _access(char *av)
{
	int rt_value;

	rt_value = access(av, X_OK);
	if (rt_value == 0)
		printf("File: %s can execute rt_value = %d\n", av, rt_value);
	else
		printf("File: %s can't execute rt_value= %d\n", av, rt_value);

	return (rt_value);
}
