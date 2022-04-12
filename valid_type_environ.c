#include "main.h"

/**
  * arv_for_execute - function that validates or execute
  * @arv: array eoth values to evaluate
  * Return: 0 char **
  */

char **arv_for_execute(char **arv)
{
	char *total, *PATH1, **new_arv = NULL, **Path_tokens;
	int i = 0, val, k = 1;

	PATH1 = malloc(sizeof(char) * 1024);
	if (PATH1 == NULL)
		return (0);
	PATH1 = getenv("PATH");
	Path_tokens = malloc(sizeof(char *) * 1024);
	if (Path_tokens == NULL)
		return (0);
	Path_tokens = tokenizer(PATH1, ":");
	total = malloc(sizeof(char) * 1024);
	if (total == NULL)
		return (0);
	new_arv = malloc(sizeof(char *) * 1024);
	while (Path_tokens[i])
	{
		total = strcpy(total, "/bin");
		total = strcat(total, "/");
		total = strcat(total, arv[0]);
		val = _access(total);
		if (val == 0)
		{
			new_arv[0] = total;
			while (arv[k])
			{
				strcpy(new_arv[k], arv[k]);
				k++;
			}
			new_arv[k] = NULL;
			free(Path_tokens);
			free(PATH1);
			return (new_arv);
		}
		i++;
	}
	free(total);
	free(Path_tokens);
	free(PATH1);
	return (NULL);
}



