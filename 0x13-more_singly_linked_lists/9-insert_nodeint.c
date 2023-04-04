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
	listint_t *ptr = *head;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	idx--;
	
	if (idx == 0)
	{
		new_node->next = ptr;
		*head = new_node;
		return (new);
	}
	else
	{
		while (idx != 0)
		{
			ptr = ptr->next;
			idx--;
		}
	}

	new_node->next = ptr->next;
	ptr->next = new_node;

	return (new_node);
}
