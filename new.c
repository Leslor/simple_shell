#include <stdio.h>

int main(void)
{
	int i = 0, j = 0, flag = 1;
	char *varname;
 	extern char **environ;
	varname = "PATH";
	while (environ[i])
	{
		if (varname[0] == environ[i][0])
		{
			flag = 1, j = 0;
			for (; varname[j]; j++)
				if (varname[j] != environ[i][j])
					flag = 0;
			if (flag && environ[i][j] == '=')
			{	
				printf("%d\n", i);
				return (i);
			}
		}
		i++;
	}
	return (-1);
}
