#include "lists.h"

/**
 * insert_nodeint_at_index -  inserts a new node at a given position
 * @head: pointer pointing to the head pointer
 * @idx: index of the list where the new node should be added,
 * index starts at 0
 * @n: data for the new node
 *
 * Return: address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *ptr = *head, *new_node;
	unsigned int i = 0;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = ptr;
		*head = new_node;
		return (new_node);
	}

	while (i < (idx - 1))
	{
		if (ptr == NULL || ptr->next == NULL)
		{
			return (NULL);
		}
		ptr = ptr->next;
		i++;
	}

	new_node->next = ptr->next;
	ptr->next = new_node;

	return (new_node);
}
