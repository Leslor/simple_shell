#include "main.h"

/**
 * main - principal function. Start the Shell program
 *
 * Return: 0 if is SUCCESS, or -1 otherwise.
 */

int main(void)
{
	char *cmd_l = NULL, *dollar = "$ ";
	int valid_built_env = 0;
	char **av = NULL;

	while (1) /*Display $ " and wait an input */
	{
		write(STDOUT_FILENO, dollar, 2);
		cmd_l = prompt();
		cmd_l = spaces(cmd_l);
		av = tokenizer(cmd_l, " \n");  /* Execute tokenizer */
		if (!av)
			exit(0);
		valid_built_env = built_or_env(av);
		valid_exec(av, valid_built_env);
		_free(av);
	}
	return (0);
}
