#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head node
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
