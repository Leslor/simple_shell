#include "main.h"

int validation(char **av)
{
	char *PATH1;
	char *new;
	char **Path_tokens;
	char *total;
	int i = 0, j = 0, count = 0;
	int val;
	extern char **environ;
	printf ("Start validation\n");
	/**/
	while (environ[j])
	{
		count+= strlen(environ[j]);
		j++;
	}
	PATH1 = malloc(sizeof(char)*(count + 1));
	PATH1 = getenv("PATH"); 
	
	Path_tokens = tokenizer(PATH1, ":");

	total = malloc(60);
	if (total == NULL)
	{
		free(PATH1);
	}
	printf("%s", *Path_tokens);
	while (Path_tokens[i])
	{
		total = strcpy(total, Path_tokens[i]);
		printf("%s\n",total);
		total = strcat(total, "/");
		printf("%s\n",total);
		new = strcat(total, av[0]);
		printf("%s\n",new);
		val =_access(new);
		if (val ==0)
		{
			break;
		}
		i++;
		printf("%d\n", val);
	}
	free(PATH1);
	_free(Path_tokens);
	free(total);
	printf("Finish Validation\n");
	return(val);
}
