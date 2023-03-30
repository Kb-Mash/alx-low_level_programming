#include "lists.h"

/**
 * free_list - list_t list
 * @head: pointer t the head of the list
 */

void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}
