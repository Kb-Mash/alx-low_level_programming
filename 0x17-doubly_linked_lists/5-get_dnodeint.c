#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head node
 * @index: index of the node, starting from 0
 * Return: the nth node, else NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (index != 0)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
		index--;
	}
	return (head);
}
