#include "lists.h"

/**
 * print_dlistint - prints all elements of a list
 * @h: pointer to the head node
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = NULL;
	size_t nodes = 0;

	current = h;
	while (current != NULL)
	{
		nodes++;
		printf("%d\n", current->n);
		current = current->next;
	}
	return (nodes);
}
