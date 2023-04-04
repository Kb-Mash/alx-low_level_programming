#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to the head pointer
 *
 * Return: 0 if list is empty,
 * else head node’s data (n)
 */

int pop_listint(listint_t **head)
{
	listint_t *ptr = *head;
	int data;

	if (*head == NULL)
	{
		return (0);
	}

	data = ptr->n;
	*head = (*head)->next;

	free(ptr);

	return (data);
}
