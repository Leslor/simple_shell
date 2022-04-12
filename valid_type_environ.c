#include "main.h"

char **arv_for_execute(char **arv)
{
		char *total, *PATH1, **new_arv = NULL;
		char **Path_tokens;
		int i = 0, val, k = 1, j = 1;

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
            	total = strcpy(total, Path_tokens[i]);
            	total = strcat(total, "/");
            	total = strcat(total, arv[0]);
            	printf("Valor concatenado :  %s\n", total);
				printf("Se valida el Access\n");
            	val = _access(total);
            	if (val == 0)
            	{
					new_arv[0] = total;/*Error especifico*/ 
					printf("new_erv[0] : %s\n",*new_arv);
					free(Path_tokens);
					while (arv[k])
					{
						new_arv[j] = arv[k];
						k++;
						j++;
					}
					printf("se termina de crear new_arv\n");
					printf("new_arv en 0 : %s\n", new_arv[0]);
					/*printf("new_arv en 1 : %s\n", new_arv[1]);*/
					printf("Voy a retornar new_arv");
					return(new_arv);
                	break;
				}
                i++;
			}
			free(total);
			free(Path_tokens);

		free(PATH1);

}		



