#include "main.h"

/**
 * main - principal function. Start the Shell program
 *
 * Return: 0 if is SUCCESS, or -1 otherwise.
 */

int main(void)
{
	char *cmd_l = NULL, *result = NULL;
	int valid_built_env = 0;
	size_t i = 0;
	char **av;

	while (1) /*Display $ " and wait an input */
	{
		cmd_l = prompt();
		if (cmd_l == NULL)
			break;
		if (strlen(cmd_l) == 1) /*no entra nada al input solo ENTER */
			continue;

		else if (strlen(cmd_l) > 1) /* entra algo más al input*/
		{
			for (i = 0; (cmd_l[i] == 32) || (cmd_l[i] == 9); i++)
				cmd_l[i] = '\0';
		}
		result = &cmd_l[i];
		av = tokenizer(result, " \n");  /* Execute tokenizer */
		if (!av)
			exit(0);
		valid_built_env = built_or_env(av);
		valid_exec(av, valid_built_env);
		_free(av);
	}
	return (0);
}
