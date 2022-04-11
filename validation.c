#include "main.h"

char **validation(char **arv)
{
        char *total, *PATH1, *first_char, *second_char, **new_arv;
        char **Path_tokens;
        int i = 0, val, k = 1, j = 1;
		char *character[] =  {".", "/"};
        
		printf ("Empezamos con la validacion\n");
        
		PATH1 = malloc(sizeof(char)*1024);
        if (PATH1 == NULL)
        	return (0);
        PATH1 = getenv("PATH"); /*Validar si requiere espacio*/
	    Path_tokens = malloc(sizeof(char *)*1024);
        if (Path_tokens == NULL)
        	return (0);
        Path_tokens = tokenizer(PATH1, ":");

        total = malloc(sizeof(char) * 1024);
        if (total == NULL)
			return (0);

		new_arv = malloc(sizeof(char)*1024);
 		/*Evaluacion de casos*/
		/*Script Case "./script"*/
		first_char = arv[0];
		second_char = arv[1];
		printf("First char: %c\n", first_char[0]);
		if (first_char[0] == *character[0] && second_char[0] == *character[1])
		{	
       		free (total);
			free (Path_tokens);
			printf("Execute an Script\n");
		}	
		/*Path Case: "/"*/
		else if (first_char[0] == *character[1])
		{
       		free (total);
			free (Path_tokens);
			printf("se ejecuta un path, enviarlo a ejecutar\n");
		}
		/*Comand Case*/
		else
		{
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
					free(total);
					free(Path_tokens);
					while (*arv != NULL)
					{
						new_arv[j] = arv[k];
						k++;
						j++;
					}	
					return(new_arv);
                	break;
				}
                i++;
			}
			free(total);
			free(Path_tokens);
		}
		free(PATH1);
		return(arv);
}
