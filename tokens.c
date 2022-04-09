#include "main.h"

char **tokenizer(char *input, char *delimt)
{
        int count = 0, i = 0;
        char **av = NULL;
        
		printf("Empezando a ejecutar\n");
        av = malloc(sizeof(char *) * 1024);

        if (!av)
		{  free(input);
			exit(-1);
		}
        while ((av[count] = strtok(input, delimt)) != NULL)
        {       
                input = NULL;
                printf("Este es el av[%d]: %s\n ", count, av[count]);
                count++;
        }
        return (av);
}
