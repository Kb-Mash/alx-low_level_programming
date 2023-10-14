#include "search_algos.h"

/**
 * jump_list - Searches for an algorithm in a sorted singly
 *             linked list of integers using jump search.
 * @list: pointer to the  head of the linked list to search
 * @size: number of nodes in the list
 * @value: value to search for
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *head, *prev;
	int i, j, jump, step = 0;

	if (list == NULL || size == 0)
		return (NULL);

	jump = sqrt(size);
	for (i = jump, prev = list, head = list; head->next; i += jump)
	{
		for (j = head->index;
			j < (int)size && head->next && (int)head->index < i;
			j++, head = head->next)
			;
		printf("Value checked at index [%ld] = [%d]\n", head->index, head->n);
		if ((head->n >= value || i >= (int)size) && !step)
		{
			if (i >= (int)size)
				i = size - 1;
			printf("Value found between indexes [%ld] and [%d]\n", prev->index, i);
			size = i + 1;
			head = prev;
			i = prev->index - 1;
			jump = 1;
			step++;
		}
		else if (head->n == value)
			return (head);

		if (step && head->n > value)
			break;
		prev = head;
	}
	return (NULL);
}
