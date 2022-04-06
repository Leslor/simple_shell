#include "main.h"

int main(void)
{
        char *cmd_l = NULL;
        size_t buf_size = 0;
        ssize_t bytes_read = 0;
        char *tokens;

             /*Display promtp " $ " and wait an input */
        while (1)
        {
                printf("$ ");
                /*Getting all the commands*/
                bytes_read = getline(&cmd_l, &buf_size, stdin);
                printf("Bytes_read : %ld\n", bytes_read);
                if (bytes_read == -1)
                {
                        if (cmd_l)
                        {
                          free(cmd_l);
                        }
                        perror("Error: ");
                        exit(1);
                }
                cmd_l[strlen(cmd_l) - 1] ='\0';
               // printf("%s",cmd_l );
                tokens = token_maker(cmd_l);
                printf("%s\n", tokens);
                /*Probando*/
                //if (tokens == NULL)
                //{
                  //free(tokens);
               //   free(cmd_l);
                //}
        }
        return(0);
}
