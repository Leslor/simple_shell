#include "main.h"

char **validation(char **arv)
{
        char *first_char, *second_char, **new_arv = NULL;
        char **Path_tokens;
		char *character[] =  {".", "/"};
		printf ("Empezamos con la validacion\n");
        
		/*Script Case "./script"*/
		first_char = arv[0];
		second_char = first_char + 1;
		
		printf("First char: %c\n", first_char[0]);
	
		if ((first_char[0] == *character[0] && second_char[0] == *character[1]) ||(first_char[0] == *character[1]))
		{	
			printf("Execute an Script\n");
			return(arv);
		}
		else
		{		
			new_arv = arv_for_execute(arv);
			return (new_arv);
		}
}
