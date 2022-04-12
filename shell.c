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

		if (strlen(cmd_l) == 1) /*no entra nada al input solo ENTER */
			continue;

		else if (strlen(cmd_l) > 1) /* entra algo más al input*/
		{
			for (i = 0; (cmd_l[i] == 32) || (cmd_l[i] == 9); i++)
			{
				cmd_l[i] = '\0';
				continue;
			}
			result = &cmd_l[i];
			printf("ahora result es: %s\n", result);
			printf("este es su len: %ld\n", strlen(result));
		}
		strcpy(cmd_l, result);
		printf("ahora cmd_l es: %s\n", cmd_l);
		printf("este es su len: %ld\n", strlen(cmd_l));
		printf("Ingresando a la funcion Tokenizer\n");
		av = tokenizer(cmd_l, " \n");  /* Execute tokenizer */

		printf("%s\n", av[0]);
		/* Validation builtin or env commands */
		valid_built_env = built_or_env(av);
		/*NOTA: Colocarlo en otra funcion*/

		printf("Pasa a la validacion y ejecucion\n");
		valid_exec(av, valid_built_env);
			_free(av);
		printf("terminado el Bucle Prompt\n");

	}
	return (0);
}
