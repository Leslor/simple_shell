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

/**
 * struct list_s - singly linked list
 * @str: string tokenized of command line arguments.
 * @next: points to the next node in the linked list.
 *
 * Description: singly linked list, the nodes are agregated at the end.
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_cmd;

list_cmd *add_node_at_end(list_cmd **head, const char *str);
char **tokenizer(char *input);
void free_list(list_cmd *head);

list_cmd *add_node_at_end(list_cmd **head, const char *str);
char **tokenizer(char *input);
void free_list(list_cmd *head);
int _execve(char **argVec);
#endif
