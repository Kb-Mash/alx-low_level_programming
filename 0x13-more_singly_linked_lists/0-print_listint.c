#include "lists.h"

/**
 * print_listint -  prints all the elements of a listint_t list
 * @h: head pointer pointing to the first node
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t n_nodes = 0;

	while (h != NULL)
	{
		n_nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (n_nodes);
}
