#include "main.h"

void valid_exec(char **av,int valid_built_env)
{
		/*NOTA: Colocarlo en otra funcion*/
		/*Execution built commands*/
		if (valid_built_env == 0 || valid_built_env == 1)
		{
				printf("Es un builtin command\n");
				_execute_built(valid_built_env);
		}
		/*Validation & execution env commands*/
		if ( valid_built_env == 2)
		{
				printf("Se verifica si es un env or un Script\n");
				av = validation(av);
				_execve(av);
				_free(av);
				printf("Se valida y se pasara a ejecutar");
		}
}