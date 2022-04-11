#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>

#define BUFSIZE 1024

/**
  * struct list_s - ...
  * @av_0: value
  * @av_1: path
  *
  * Description: Structure of av
  * lits_t: av typedef structure
  */
typedef struct list_s
{
	int av_0;
	char *av_1;
} list_t;

void _free(char **av);
int built_or_env(char **av);
void _execute_built(int i);
void _valid_execve(char **argVec);
char **validation(char **arv);
int _access(char *av);
void _execve(char **argVec);
/*Validar*/
char **tokenizer(char *input, char *delimit);
void free_list(list_t *d);
void valid_exec(char **av, int valit_built_env);
#endif
