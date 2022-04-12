#include "main.h"

/*
NULL(string de caracteres en nulo) = "\0\0\0\0";
nulo(caracter nulo) = '\0';
*/

void _free(char **av)
{
        int i = 0;
        if (*(av + i)) /* *(av + 1) == av[1] */
        {
                free(*(av + i));
        }
        free(av);
}
