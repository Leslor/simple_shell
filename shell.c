
#include "main.h"

int main(void)
{
        char *cmd_l = NULL, *result = NULL;
        int valid_built_env = 0;
        size_t i = 0;
        size_t buf_size = 0;
        ssize_t bytes_read = 0;
        char **av;
        
        /*Display $ " and wait an input */
        while (1)
        {
                printf("Empezamos el bucle con Prompt\n");
                buf_size = 0;
                bytes_read = 0;
                valid_built_env = 0;
                printf("$ ");
                bytes_read = getline(&cmd_l, &buf_size, stdin);
                printf("%ld\n", bytes_read);
                if (bytes_read == -1)
                {
                        if (cmd_l)
                                free(cmd_l);
                        return (0);
                }

                if (strlen(cmd_l) == 1) /*no entra nada al input solo ENTER */
                       continue;

                else if (strlen(cmd_l) > 1) /* entra algo más al input*/
                {
                        for (i = 0; (cmd_l[i] == 32) || (cmd_l[i] == 9); i++)
                        {
                                cmd_l[i] = '\0';
                                continue;
                        }
                        result = &cmd_l[i];
                        /*free(cmd_l);*/
                        printf("ahora result es: %s\n", result);
                        printf("este es su len: %ld\n", strlen(result));
                }
                strcpy(cmd_l, result);
                printf("ahora cmd_l es: %s\n", cmd_l);
                printf("este es su len: %ld\n", strlen(cmd_l));
                /* Execute tokenizer */
                printf("Ingresando a la funcion Tokenizer\n");
                av = tokenizer(cmd_l, " \n");


                printf("%s\n", av[0]);
                /* Validation builtin or env commands */
                valid_built_env = built_or_env(av);
                /*NOTA: Colocarlo en otra funcion*/

				printf("Pasa a la validacion y ejecucion\n");
               valid_exec(av, valid_built_env);
				
			   _free(av);
                printf("terminado el Bucle Prompt\n");
                
                printf("Saliste del Bucle: esto depende de EXIT\n");
		}
        return (0);
}
