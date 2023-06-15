#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: address of the pointer to the head node
 * @n: data to add to the new node
 * Return: address of the new node, else NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = NULL;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
