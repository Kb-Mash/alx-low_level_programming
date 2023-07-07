#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	int index = 0;
	char *value_cp = NULL;
	hash_node_t *new_node = NULL;
	hash_node_t *head = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || !value)
		return (0);
	value_cp = strdup(value);
	if (!value_cp)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index] && !strcmp(ht->array[index]->key, key))
	{
		free(ht->array[index]->value);
		ht->array[index]->value = value_cp;
		return (1);
	}
	for (head = ht->array[index]; head; head = head->next)
	{
		if (!strcmp(head->key, key))
		{
			free(head->value);
			head->value = value_cp;
			return (1);
		}
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	if (!new_node->key)
		return (0);
	new_node->value = value_cp;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
