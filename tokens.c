#include "main.h"


char **tokenizer(char *input)
{
        int count = 0, i = 0;
        char **av = NULL;
        
	printf("Empezando a ejecutar\n");
        av = malloc(sizeof(char *) * 1024);

        if (!av)
                exit(-1);

        while ((av[count] = strtok(input, " ")) != NULL)
        {       
                input = NULL;
                printf("Este es el av[%d]: %s\n ", count, av[count]);
                count++;
        }
        while (av[i] != NULL)
        {
                printf("free[%d] -> %s\n",i, av[i]);
                i++;
        }
        free(input);
       
        return (av);
}
