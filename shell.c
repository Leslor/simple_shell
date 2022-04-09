#include "main.h"

int main(void)
{
	char *cmd_l = NULL;
	int validation1;
	size_t buf_size = 0;
	ssize_t bytes_read = 0;
	char *exi = "exit";	
	char **av;
	/*Display $ " and wait an input */
	while (1)
	{
		buf_size = 0;
		printf("$ ");
		bytes_read = getline(&cmd_l, &buf_size, stdin);
		printf("%ld\n", bytes_read);
		if (bytes_read == -1)
		{
			if (cmd_l)
				free(cmd_l);
			return (0);
		}

		if (strlen(cmd_l) == 1)
			continue;

		/* Execute tokenizer */
		av = tokenizer(cmd_l, " \n");

		/* Exit to the sistem: */
		if (strcmp(av[0], exi) == 0)
		{
				printf("Saliendo del sistema\n");
				_free(av);
				break;
		}

		/*Validation*/	
		validation1 = validation(av);
		if (validation1 == 0)
		{
			_execve(av);
		}
		else
		{
			perror(av[0]);
		}

		/* Free **av */
		_free(av);
	}
	return (0);
}
