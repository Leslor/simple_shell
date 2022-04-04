#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>


#define BUFFER 1024

/**
* struct lists_t - linked list of commands
* @cmd: command
* @next: pointer to next node
*
* Description: linked_list struct for commands
*/
typedef struct lists_t
{
char *cmd;
struct list_t *next;
} list_cmd;

#endif /* MAIN_H */
