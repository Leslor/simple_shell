#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

unsigned int only_spaces(char *str)
{
        unsigned int flag = 1, i = 0;

        while (str[i] == 32)
                i++;

        if (str[i] != '\0')
                flag = 0;

        return (flag);
}
void do_the_cmd(char *cmd)
{
        pid_t child_pid = 0;
        int status_child = 0;
        char *instructions[] = {cmd, NULL};

        if (only_spaces(cmd))
                return;

        child_pid = fork();

        if (child_pid == -1)
        {
                _exit(1);
        }
        else if (child_pid == 0)
        {
                if (access(cmd, F_OK) == 0)
                        execve(instructions[0], instructions, NULL);
                else
                        printf("%s: command not found\n", cmd);
                free(cmd);
                _exit(1);
        }
        else
        {
                wait(&status_child);
                free(cmd);
        }
}


int main(void)
{
        size_t n = 0;
        ssize_t size_ln = 0;
        char *cmd = NULL;

        while (1)
        {
         /* cmd = NULL; */
                printf("$ ");
                size_ln = getline(&cmd, &n, stdin);
                if (size_ln == EOF)
                {
                        if (cmd)
                                free(cmd);
                        printf("\n");
                        exit(1);
                }

                cmd[strlen(cmd) - 1] = '\0';

                if (strlen(cmd) < 1)
                {
                        free(cmd);
                        continue;
                }

                do_the_cmd(cmd);
        }
        return (0);
}
