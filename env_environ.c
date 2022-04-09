#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
        extern char **environ;

        printf("env in main: %p\n", env);
        printf("Environ: %p\n", environ);
        return (0);
}
