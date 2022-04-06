#include "main.h"

char *token_maker(char *input)
{ 
        unsigned int count = 0;
        char *copy, *token;


        copy = strdup(input);
        printf("%s\n", copy);
 
        token = strtok(copy, "|");
                
        while( token != NULL ) 
        {
                //node = add_node_end(&head, token);
                printf("%s\n", token);
                token = strtok(NULL, "|");
        }
  
 // return (node);

        free(token);
       
        return(copy);
}

