#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: address of the pointer to the head node
 * @n: data to add to new node
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = NULL, *current = NULL;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;

	return (new);
}
