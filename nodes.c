#include "main.h"

list_cmd *add_node_at_end(list_cmd **head, const char *str)
{
	list_cmd *new_node, *temp;
        printf("ingrese a tokenizer\n");

	new_node = malloc(sizeof(list_cmd));
	if (!new_node)
		return (NULL);
	temp = *head;
	if (*head == NULL)
	{
	        *head = new_node;
		//return (new_node);
	}
        else{
                while (temp->next != NULL)
                {
                        temp = temp->next;
	                temp->next = new_node;
                }        
        }
        new_node->str = strdup(str);
        if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
        printf("%s\n",new_node->str );
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_list - Frees a list_t list.
 * @head: A pointer to the list_t list.
 */
void free_list(list_cmd *head)
{
	list_cmd *ptr;

	while (head)
	{
		ptr = head->next;
		free(head->str);
		free(head);
		head = ptr;
	}
}
