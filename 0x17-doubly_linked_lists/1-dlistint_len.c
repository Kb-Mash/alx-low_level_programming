#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked list
 * @h: pointer to the head node
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t elements = 0;

	while (current)
	{
		elements++;
		current = current->next;
	}
	return (elements);
}
