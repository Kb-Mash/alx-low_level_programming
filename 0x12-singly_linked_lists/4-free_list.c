#include "lists.h"

/**
 * free_list - list_t list
 * @head: pointer t the head of the list
 */

void free_list(list_t *head)
{
	if (head)
	{
		while (head->next)
		{
			free(head->str);
			head = head->next;
		}
		free(head);
	}
}
