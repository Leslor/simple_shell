#include "main.h"

char **tokenizer(char *input)
{
	int count = 0, i = 0;
	char *t, **av, *copy;
	list_cmd *head = NULL;
	struct stat st;

	/*copy = strdup(input);*/    /* input = string[] = {"tail -l -n"} */
	/* free(input);*/
	t = strtok(input, " ");
	while (t)
	{
		add_node_at_end(&head, t);        /* {"tail", "-l", "-n"}*/
		count++;
		t = strtok(NULL, " ");
	}
	/* free(copy);*/                                /* copy doesn't exist */
	av = malloc(sizeof(char *) * (count));

        while (i < count)
	{
		av[i] = strdup(head->str);
		head = head->next;
                printf("Este es el av %i: %s\n", i, av[i]);
		i++;
	}
        av[count] = NULL;

        
        free_list(head);
	
	return (av);
}
