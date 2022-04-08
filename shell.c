#include "main.h"

int main(void)
{
	char *cmd_l = NULL;
	char **av;
	size_t buf_size = 0;
	ssize_t bytes_read = 0;

/*Display promtp "$ " and wait an input */
	while (1)
	{
		printf("$ ");
		bytes_read = getline(&cmd_l, &buf_size, stdin);
		printf("%ld\n", bytes_read);
		if (bytes_read == -1)
		{
			if (cmd_l)
				free(cmd_l);
			return (0);
		}
		/*cmd_l[strlen(cmd_l) - 1] = '\0';*/
		
		if (strlen(cmd_l) == 1)
			continue;
		
/* Execute tokenizer */
		av = tokenizer(cmd_l); 
/* Executes the program referred to by avg*/
		_free(av);
	}
	return (0);
}
