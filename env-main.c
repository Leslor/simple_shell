#include <stdio.h>
#include <unistd.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i = 0;
	extern char **environ;

	while(environ[i]!= NULL)
	{	
			if(environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i][2] == 'T')
			{
			printf("%s\n", environ[i]);
			}
			i++;
	}
	return (0);
}
