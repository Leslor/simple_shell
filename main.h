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

extern char **environ;
char *spaces(char *input);
void _free(char **av);
void free_env(void);
int built_or_env(char **av);
void _execute_built(int i);
void _valid_execve(char **argVec);
char **validation(char **arv);
int _access(char *av);
void _execve(char **argVec);
char *prompt(void);
char **tokenizer(char *input, char *delimit);
void valid_exec(char **av, int valit_built_env);
char **arv_for_execute(char **arv);

#endif /*MAIN_H*/
