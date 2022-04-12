#include "main.h"


char **arv_for_execute(char **arv)
{
		char *total, *PATH1, **new_arv = NULL;
		char **Path_tokens;
		int i = 0, val, k = 1;

		PATH1 = malloc(sizeof(char)*1024);
       
		if (PATH1 == NULL)
        	return (0);
		PATH1 = getenv("PATH");

		Path_tokens = malloc(sizeof(char *)*1024);
        if (Path_tokens == NULL)
				return (0);
		Path_tokens = tokenizer(PATH1, ":");

		total = malloc(sizeof(char) * 1024);
        if (total == NULL)
			return (0);

		new_arv = malloc(sizeof(char*) * 1024);

		while (Path_tokens[i])
        {
				total = strcpy(total, "/bin");
            	total = strcat(total, "/");
            	total = strcat(total, arv[0]);
            	printf("Valor concatenado :  %s\n", total);
				printf("Se valida el Access\n");
            	val = _access(total);
            	if (val == 0)
				{
						printf("NEW NEW NEW NEW\n");
						new_arv[0] = total;
			printf("new_erv[0] : %s\n",*new_arv);	
			while (arv[k])
			{
				printf("ENTRA AL WHILE\n");
				strcpy(new_arv[k], arv[k]);
				k++;
			}
				printf("se termina de crear new_arv\n");
						printf("new_arv en 0 : %s\n", new_arv[0]);
						printf("Voy a retornar new_arv");
						new_arv[k] = NULL;
						free(Path_tokens);
						free(PATH1);
						return(new_arv);
				}
				i++;
		}
		free(total);/*Validar si se borrara*/
		free(Path_tokens);
		free(PATH1);
		return(NULL);
}		



