#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer pointing to the head pointer
 * Return:  pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *ptr = NULL, *previous = NULL;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}

	while (*head != NULL)
	{
		ptr = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = ptr;
	}

	*head = previous;

	return (*head);
}
